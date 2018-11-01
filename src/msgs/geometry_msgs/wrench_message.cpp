//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/wrench_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

WrenchMessage::WrenchMessage(const ros_types::Vector3 &force, const ros_types::Vector3 &torque)
  : force(force),
    torque(torque),
    ros_msg_type("geometry_msgs/Wrench")
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value WrenchMessage::createJsonMsg() const
{
  Vector3Message f(force);
  Vector3Message t(torque);

  json::value geometry_msgs_json;
  geometry_msgs_json[U("force")] = f.getJsonAt("msg");
  geometry_msgs_json[U("torque")] = f.getJsonAt("msg");
  return geometry_msgs_json;
}
