//
// Created by Julian
//

#include <ros_bridge_client/msgs/rbc_subscribe_message.h>

using namespace ros_bridge_client::msgs;
using namespace web;

RBCSubscribeMessage::RBCSubscribeMessage()
{
  json[U("topic")] = json::value::string("invalid");
  json[U("type")] = json::value::string("invalid");
  json[U("msg")] = json::value::string("invalid");

  try
  {
    json.erase("op");
  } catch (const std::exception &e)
  {
    std::cerr << "Can't delete key 'op': " << e.what() << std::endl;
  }
}

RBCSubscribeMessage::RBCSubscribeMessage(std::string topic, std::string ros_msg_type,
                                         const web::json::value &msg)
{
  json[U("topic")] = json::value::string(topic);
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = msg;

  try
  {
    json.erase("op");
  } catch (const std::exception &e)
  {
    std::cerr << "Can't delete key 'op': " << e.what() << std::endl;
  }
}
