//
// Created by Julian on 05.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

Vector3Message::Vector3Message(const double x, const double y, const double z)
  : Point(x, y, z), ros_type("geometry_msgs/Vector3")
{
  json[U("type")] = json::value::string(ros_type);
}

Vector3Message::Vector3Message(const ros_bridge_client::ros_types::Vector3 &vec)
  : Point(vec.x, vec.y, vec.z), ros_type("geometry_msgs/Vector3")
{
  json[U("type")] = json::value::string(ros_type);
}
