//
// Created by Julian on 18.10.18.
//

#include <rbc/msgs/message.h>
#include <rbc/ros_bridge_client.h>
#include <rbc/publisher/rbc_publisher.h>
#include <rbc/subscriber/rbc_subscriber.h>
#include <rbc/service/service_handler.h>
#include <rbc/exceptions/connection_exception.h>
#include <rbc/utils/deserializer.h>

using namespace web::web_sockets::client;
using namespace rbc;

ROSBridgeClient::ROSBridgeClient(const std::string addr)
    : log(), ws_client(), subscribers(), services()
{
  subscribers.reserve(100); // TODO make variable
  connect(addr);
  receive();
}

std::shared_ptr<ROSBridgeClient> ROSBridgeClient::init(std::string addr)
{
  // have to jump trough loops because ROSBridgeClient constructor is protected
  // https://stackoverflow.com/a/8147213
  // example https://stackoverflow.com/a/25069711
  struct make_share_enabler : public ROSBridgeClient
  {
    make_share_enabler(std::string addr) : ROSBridgeClient(addr)
    {}

    ~make_share_enabler() override = default;
  };
  static auto manager = std::make_shared<make_share_enabler>(addr);
  return manager;
}

template<typename T>
std::shared_ptr<publisher::RBCPublisher<T>> ROSBridgeClient::addPublisher(std::string topic)
{
  auto pub = std::make_shared<publisher::RBCPublisher<T>>(shared_from_this(), topic, T().rosMsgType());
  return pub;
}

template<typename T>
std::shared_ptr<subscriber::RBCSubscriber<T>>
ROSBridgeClient::addSubscriber(std::string topic, size_t buffer_size, std::function<void(std::shared_ptr<T>)> cb)
{
  auto sub = std::make_shared<subscriber::RBCSubscriber<T>>(shared_from_this(), topic, T().rosMsgType(),
                                                            buffer_size, cb);
  subscribers[topic] = sub; // TODO check for duplicates
  return sub;
}

template<typename T>
std::shared_ptr<ServiceHandler<T>> ROSBridgeClient::addServiceHandler(std::string name,
                                                                      std::string response_name,
                                                                      std::function<void(std::shared_ptr<T>)> cb)
{
  auto srv = std::make_shared<srv::ServiceHandler<T>>(shared_from_this(), name, response_name, cb);
  services[name] = srv;
  return srv;
}


ROSBridgeClient::~ROSBridgeClient()
{
  ws_client.close().then([]()
                         {
                           std::cout << "Closing Connection\n";
                         }).wait();

  std::cout << "Closed Connection\n";
}

void ROSBridgeClient::connect(const std::string addr)
{
  try
  {
    ws_client.connect(U(addr)).then([&]()
                                    {
                                      std::cout << "Attempting to connect to " << addr << "\n";
                                    }).wait();
  }
  catch (const std::exception &e)
  {
    throw exception::ConnectionException();
  }

  std::cout << "Successfully connect to " << addr << "\n";
}

void ROSBridgeClient::send(const web::json::value &msg)
{
  json::value test;
  try
  {
    test = msg.at("op");
  }
  catch (std::exception &e)
  {
    std::cerr << "Message malformed. Key 'op' missing. Not sending.\n";
    return;
  }

  // convert json to string and send
  websocket_outgoing_message m;
  m.set_utf8_message(utils::Deserializer::toString(msg));

  try
  {
    ws_client.send(m).wait();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Failed to send: " << utils::Deserializer::toString(msg) << ": " << e.what() << std::endl;
  }
}

void ROSBridgeClient::send(const std::string msg)
{
  websocket_outgoing_message m;
  m.set_utf8_message(msg);

  try
  {
    ws_client.send(m).wait();
  }
  catch (const std::exception &e)
  {
    std::cerr << "Failed to send: " << msg << ": " << e.what() << std::endl;
  }
}

void ROSBridgeClient::receive()
{
  ws_client.set_message_handler([&](websocket_incoming_message msg)
                                {
                                  auto msg_str = msg.extract_string().get();
                                  web::json::value response = web::json::value::parse(U(msg_str));

                                  log.log("Received ", msg_str);

                                  callHandler(response);
                                });
}

void ROSBridgeClient::callSubscriberHandler(const web::json::value &response)
{
  if (subscribers.empty())
  {
    std::cerr << "Can't subscribe. No Subscribers.\n";
    return;
  }

  std::string topic_received;

  try
  {
    topic_received = response.at(U("topic")).as_string();
  }
  catch (std::exception &e)
  {
    std::cerr << "Message malformed? Can't get topic: " << e.what() << "\n";
    return;
  }

  if (subscribers.find(topic_received) != std::end(subscribers))
  {
    auto sub = subscribers.at(topic_received).lock();
    if (not sub)
    {
      std::cout << "Sub nullptr. Y?!\n";
      return;
    }

    sub->addMessage(response);
  }
  else
  {
    std::cout << "Topic '" << topic_received << "' doesn't seems to be subscribed to!\n";
  }
}

void ROSBridgeClient::callServiceResponseHandler(const web::json::value &response)
{
  if (services.empty())
  {
    std::cerr << "Can't receive service response. No Services registerd\n";
    return;
  }

  std::string service_name;

  try
  {
    service_name = response.at(U("service")).as_string();
  }
  catch (std::exception &e)
  {
    std::cerr << "Message malformed? Can't get service name: " << e.what() << "\n";
    return;
  }

  if (services.find(service_name) != std::end(services))
  {
    auto srv = services.at(service_name).lock();
    if (not srv)
    {
      std::cout << "Srv nullptr. Y?!\n";
      return;
    }

    srv->addResponse(response);
  }
  else
  {
    std::cerr << "Can't process service name " << service_name << ". Not registered?!\n";
  }

}

void ROSBridgeClient::callHandler(const web::json::value &response)
{
  std::string resp_type;

  try
  {
    resp_type = response.at(U("op")).as_string();
  }
  catch (std::exception &e)
  {
    std::cerr << "Not a known message: neither publisher on rosbridge side or returning service call\n";
    std::cerr << e.what() << "\n";
    std::cerr << "Full received_message: " << response << "\n";
    return;
  }

  if (resp_type == "publish")
  {
    callSubscriberHandler(response);
  }
  else if (resp_type == "service_response")
  {
    callServiceResponseHandler(response);
  }
  else
  {
    std::cerr << "Received unknown received_message of type " << resp_type << "\n";
  }
}
