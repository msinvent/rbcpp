//
// Created by Julian
// TODO how to handle child frame id vs header?
//

#include <ros_bridge_client/msgs/geometry_msgs/transform_stamped_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

TransformStampedMessage::TransformStampedMessage(const ros_types::Vector3 &translation,
                                                 const ros_types::Quaternion &rotation, std::string child_frame_id)
  : TransformMessage(translation, rotation),
    ros_msg_type("geometry_msgs/TransformStamped"),
    child_frame_id(child_frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value TransformStampedMessage::createJsonMsg() const
{
  json::value geometry_msgs_json;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_message(child_frame_id);
  geometry_msgs_json[U("header")] = header_message.getJsonAt("msg");
  geometry_msgs_json[U("child_frame_id")] = json::value::string(child_frame_id);
  geometry_msgs_json[U("transform")] = RBCMessage::getJsonAt("msg");

  return geometry_msgs_json;
}
