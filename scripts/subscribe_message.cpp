//
// Created by Julian
//

#include <rbc/msgs/std_msgs/subscribe_message.h>

using namespace rbc::msgs::std_msgs;
using namespace web;

SubscribeMessage::SubscribeMessage()
  : ros_msg_type("std_msgs/ColorRGBA")
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value SubscribeMessage::createJsonMsg() const
{
  json::value subscribe_message_json;
  return subscribe_message_json;
}
