//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/twist_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

TwistMessage::TwistMessage(const ros_types::Vector3 &linear, const ros_types::Vector3 &angular)
  : Accel(linear, angular), ros_msg_type("geometry_msgs/Twist")
{
  json[U("type")] = json::value::string(ros_msg_type);
}

TwistMessage::TwistMessage(double lx, double ly, double lz, double ax, double ay, double az)
  : Accel(lx, ly, lz, ax, ay, az), ros_msg_type("geometry_msgs/Twist")
{
  json[U("type")] = json::value::string(ros_msg_type);
}
