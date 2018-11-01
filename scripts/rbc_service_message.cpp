//
// Created by Julian
//

#include <ros_bridge_client/msgs/std_msgs/rbc_service_message.h>

using namespace ros_bridge_client::msgs::std_msgs;
using namespace web;

RBCServiceMessage::RBCServiceMessage()
  : ros_msg_type("std_msgs/ColorRGBA")
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value RBCServiceMessage::createJsonMsg() const
{
  json::value rbc_service_message_json;
  return rbc_service_message_json;
}
