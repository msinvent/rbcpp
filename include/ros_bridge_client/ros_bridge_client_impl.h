//
// Created by Julian on 18.10.18.
//

#include <ros_bridge_client/ros_bridge_client.h>
#include <ros_bridge_client/publisher/rbc_publisher.h>
#include <ros_bridge_client/subscriber/rbc_subscriber.h>
#include <ros_bridge_client/exceptions/connection_exception.h>

using namespace web::web_sockets::client;
using namespace ros_bridge_client;

ROSBridgeClient::ROSBridgeClient(const std::string addr) : connected(false)
{
  connect(addr);
  receive();
}

std::shared_ptr<ROSBridgeClient> ROSBridgeClient::init(std::string addr)
{
  // have to jump trough loops because of https://stackoverflow.com/a/8147213
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
  T ros_type;
  auto pub = std::make_shared<publisher::RBCPublisher<T>>(shared_from_this(), topic, ros_type.rosMsgType());
  return pub;
}

template<typename T>
std::shared_ptr<subscriber::RBCSubscriber<T>>
ROSBridgeClient::addSubscriber(std::string topic, size_t buffer_size, std::function<void(std::shared_ptr<T>)> cb)
{
  T ros_type;
  auto sub = std::make_shared<subscriber::RBCSubscriber<T>>(shared_from_this(), topic, ros_type.rosMsgType(),
                                                            buffer_size, cb);
  subscribers.push_back(sub);
  return sub;
}

ROSBridgeClient::~ROSBridgeClient()
{
  if (connected)
  {
    ws_client.close().then([]() {
      std::cout << "Closing Connection\n";
    }).wait();
  }

  connected = false;
}

void ROSBridgeClient::connect(const std::string addr)
{
  try
  {
    ws_client.connect(U(addr)).then([&]() {
      connected = true;
    }).wait();
  }
  catch (const std::exception &e)
  {
    throw exception::ConnectionException();
  }

  std::cout << "Successfully connect to " << addr << std::endl;
}

void ROSBridgeClient::send(const msgs::RBCMessage &msg)
{
  if (!connected)
  {
    std::cerr << "Can't send: Not connected" << std::endl;
    return;
  }

  json::value test;
  try
  {
    test = msg.msg().at("op");
  }
  catch (std::exception &e)
  {
    std::cerr << "Message malformed. Key 'op' missing. Not sending.\n";
    return;
  }

  // convert json to string and send
  websocket_outgoing_message m;
  m.set_utf8_message(RBCMessage::toString(msg.msg()));

  try
  {
    ws_client.send(m).then([&]() {}).wait();
  } catch (const std::exception &e)
  {
    std::cerr << "Failed to send: " << e.what() << std::endl;
  }
}

void ROSBridgeClient::send(const msgs::RBCMessage *msg)
{
  send(*msg);
}


void ROSBridgeClient::send(const web::json::value &msg)
{
  if (!connected)
  {
    std::cerr << "Can't send: Not connected" << std::endl;
    return;
  }

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
  m.set_utf8_message(RBCMessage::toString(msg));

  try
  {
    ws_client.send(m).then([&]() {}).wait();
  } catch (const std::exception &e)
  {
    std::cerr << "Failed to send: " << e.what() << std::endl;
  }
}

void ROSBridgeClient::send(const std::string msg)
{
  if (!connected)
  {
    std::cerr << "Can't send. Not connected" << std::endl;
    return;
  }

  websocket_outgoing_message m;
  m.set_utf8_message(msg);
  ws_client.send(m).then([&]() {}).wait();
}

void ROSBridgeClient::receive()
{
  ws_client.set_message_handler([&](websocket_incoming_message msg) {
    if (subscribers.empty())
      return;

    auto msg_str = msg.extract_string().get();

    log.log("Received ", msg_str);

    web::json::value json = web::json::value::parse(U(msg_str));

    try
    {
      json.at(U("topic"));
    }
    catch (const std::exception &e)
    {
      std::cerr << "Can't get key 'topic'. Subscribed message is wrong" << e.what() << std::endl;
      return;
    }

    const auto &topic_received = json.at(U("topic")).as_string();

    for (auto &subscriber: subscribers)
    {
      try
      {
        auto sub = subscriber.lock();
        if (topic_received != sub->getTopic()) continue;
        sub->addMessage(json);
      } catch (std::bad_weak_ptr b)
      {
        std::cerr << "can't send message to subscriber: " << b.what() << "\n";
      }

    }
  });
}

bool ROSBridgeClient::connectionOk() const
{
  return connected;
}
