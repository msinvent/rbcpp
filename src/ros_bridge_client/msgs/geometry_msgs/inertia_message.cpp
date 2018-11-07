//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/inertia_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>
#include <ros_bridge_client/ros_types/ros_types.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

InertiaMessage::InertiaMessage(double m, const ros_bridge_client::ros_types::Vector3 &com, double ixx, double ixy,
                               double ixz, double iyy,
                               double iyz, double izz)
  : ros_msg_type("geometry_msgs/Inertia"),
    m(m), com(com),
    ixx(ixx), ixy(ixy), ixz(ixz),
    iyy(iyy), iyz(iyz), izz(izz)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value InertiaMessage::createJsonMsg() const
{
  json::value geometry_msgs_json;
  geometry_msgs_json[U("m")] = m;
  geometry_msgs_json[U("ixx")] = ixx;
  geometry_msgs_json[U("ixy")] = ixy;
  geometry_msgs_json[U("ixz")] = ixz;
  geometry_msgs_json[U("iyy")] = iyy;
  geometry_msgs_json[U("iyz")] = iyz;
  geometry_msgs_json[U("izz")] = izz;

  Vector3Message com_vec(com);
  geometry_msgs_json[U("com")] = com_vec.getJsonAt("msg");

  return geometry_msgs_json;
}
