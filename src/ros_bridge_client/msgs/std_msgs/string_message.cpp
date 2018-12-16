//
// Created by Julian on 14.09.18.
//

#include <cpprest/ws_client.h>
#include <rbc/msgs/std_msgs/string_message.h>

using namespace rbc::msgs::std_msgs;
using namespace web;
using namespace web::web_sockets::client;

StringMessage::StringMessage(const std::string data)
  : data_(data),
    ros_type("std_msgs/String")
{
  // add to json ROS message and complete it
  json[U("msg")] = createJsonMsg();
  json[U("type")] = json::value::string(ros_type);
}

StringMessage::StringMessage(const web::json::value &msg)
  : data_(msg.at("msg").at("data").as_string()),
    ros_type("std_msgs/String")
{
  json[U("msg")] = msg.at("msg");
  json[U("type")] = json::value::string(ros_type);
}

web::json::value StringMessage::createJsonMsg() const
{
  json::value msg;
  msg[U("data")] = json::value::string(data_);
  return msg;
}
