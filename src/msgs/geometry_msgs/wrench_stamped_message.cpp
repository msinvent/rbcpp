//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

WrenchStampedMessage::WrenchStampedMessage(const ros_types::Vector3 &force, const ros_types::Vector3 &torque,
                                           std::string frame_id)
  : WrenchMessage(force, torque),
    ros_msg_type("geometry_msgs/WrenchStamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value WrenchStampedMessage::createJsonMsg() const
{
  json::value geometry_msgs_json;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_message(frame_id);
  geometry_msgs_json[U("header")] = header_message.getJsonAt("msg");
  geometry_msgs_json[U("wrench")] = RBCMessage::getJsonAt("msg");

  return geometry_msgs_json;
}
