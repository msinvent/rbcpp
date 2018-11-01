//
// Created by Julian on 14.09.18.
//

#include <ros_bridge_client/ros_bridge_client.h>

using namespace web::web_sockets::client;
using namespace ros_bridge_client;
using namespace std::chrono_literals;

ROSBridgeClient::ROSBridgeClient(const std::string addr) : connected(false)
{
  std::cout << "Trying to connect to " << addr << std::endl;
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

ROSBridgeClient::~ROSBridgeClient()
{
  if (connected)
  {
    for (auto subscriber: subscribers)
    {
      send(subscriber->unsubscribeMsg());
    }

    ws_client.close().then([]() {
      std::cout << "Closing Connection" << std::endl;
    }).wait();
  }

  connected = false;
}

void ROSBridgeClient::connect(const std::string addr)
{
  try
  {
    ws_client.connect(U(addr)).then([&]() {
      std::cout << "Connected to " << addr << std::endl;
      connected = true;
    }).wait();
  } catch (const std::exception &e)
  {
    std::cerr << "Can't connect: " << e.what() << std::endl;
  }
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

  // convert json to string
  websocket_outgoing_message m;
  utility::stringstream_t stream;
  msg.msg().serialize(stream);
  m.set_utf8_message(stream.str());

  try
  {
    ws_client.send(m).then([&]() {
      std::cout << stream.str() << std::endl;
    }).wait();
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

  // convert json to string
  websocket_outgoing_message m;
  utility::stringstream_t stream;
  msg.serialize(stream);
  m.set_utf8_message(stream.str());

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
      if (topic_received != subscriber->getTopic()) continue;

      subscriber->addMessage(json);
    }
  });
}

bool ROSBridgeClient::connectionOk() const
{
  return connected;
}
