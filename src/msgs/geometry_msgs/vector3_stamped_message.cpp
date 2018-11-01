//
// Created by Julian on 05.10.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/vector3_stamped_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

Vector3StampedMessage::Vector3StampedMessage(double x, double y, double z, std::string frame_id)
  : Vector3Message(x, y, z),
    ros_type("geometry_msgs/Vector3Stamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_type);
  json[U("msg")] = createJsonMsg();
}

Vector3StampedMessage::Vector3StampedMessage(const ros_types::Vector3 &vec, std::string frame_id)
  : Vector3Message(vec),
    ros_type("geometry_msgs/Vector3Stamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_type);
  json[U("msg")] = createJsonMsg();
}

json::value Vector3StampedMessage::createJsonMsg() const
{
  json::value json_vector3;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_msg(frame_id);

  json_vector3[U("header")] = header_msg.getJsonAt("msg");

  // vector is Point32Message field msg: set in Point32Message constructor
  json_vector3[U("vector")] = RBCMessage::getJsonAt("msg");

  return json_vector3;
}
