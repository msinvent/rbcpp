//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/transform_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

TransformMessage::TransformMessage(const ros_types::Vector3 &translation, const ros_types::Quaternion &rotation)
  : translation(translation),
    rotation(rotation),
    ros_msg_type("geometry_msgs/Transform")
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value TransformMessage::createJsonMsg() const
{
  json::value geometry_msgs_json;

  using namespace ros_bridge_client::msgs::geometry_msgs;
  Vector3Message vec3_msg(translation);
  QuaternionMessage q_msg(rotation);

  geometry_msgs_json[U("rotation")] = q_msg.getJsonAt("msg");
  geometry_msgs_json[U("translation")] = vec3_msg.getJsonAt("msg");

  return geometry_msgs_json;
}
