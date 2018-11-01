//
// Created by Julian
//

#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

InertiaStampedMessage::InertiaStampedMessage(double m,
                                             const ros_bridge_client::ros_types::Vector3 &com,
                                             double ixx, double ixy, double ixz,
                                             double iyy, double iyz, double izz,
                                             std::string frame_id)
  : InertiaMessage(m, com, ixx, ixy, ixz, iyy, iyz, izz),
    ros_msg_type("geometry_msgs/InertiaStamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value InertiaStampedMessage::createJsonMsg() const
{
  json::value geometry_msgs_json;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_message(frame_id);
  geometry_msgs_json[U("header")] = header_message.getJsonAt("msg");
  geometry_msgs_json[U("inertia")] = RBCMessage::getJsonAt("msg");

  return geometry_msgs_json;
}
