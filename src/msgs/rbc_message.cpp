//
// Created by Julian on 14.09.18.
//

#include <ros_bridge_client/msgs/rbc_message.h>
#include <cpprest/ws_client.h>

using namespace ros_bridge_client::msgs;
using namespace web;

RBCMessage::RBCMessage()
  : topic("/rosbridge/message")
{
  // these are just default values. They are finally set in publisher/subscriber in publish/subcribe methods
  json[U("op")] = json::value::string("publish");
  json[U("topic")] = json::value::string(topic);
  fallback_json[U("msg")] = json::value::string("INVALID");
}

RBCMessage::RBCMessage(std::string op)
{
  json[U("op")] = json::value::string(op);
  fallback_json[U("msg")] = json::value::string("INVALID");
}

void RBCMessage::setTopic(std::string t)
{
  json[U("topic")] = json::value::string(t);
}

void RBCMessage::setMode(std::string op)
{
  json[U("op")] = json::value::string(op);
}

const json::value &RBCMessage::getJsonAt(std::string key) const
{
  json::value msg;
  try
  {
    return json.at(U(key));
  } catch (const std::exception &e)
  {
    std::cerr << "Can't get key 'msg': returning empty message; " << e.what() << std::endl;
  }

  return fallback_json.at(U("msg"));
}

json::value RBCMessage::createJsonMsg() const
{
  json::value msg;
  return msg;
}

const json::value &RBCMessage::msg() const
{
  return json;
}

std::string RBCMessage::toString() const
{
  web_sockets::client::websocket_outgoing_message m;
  utility::stringstream_t stream;
  msg().serialize(stream);
  return stream.str();
}

std::string RBCMessage::toString(const json::value &json)
{
  utility::stringstream_t stream;
  json.serialize(stream);
  return stream.str();
}
