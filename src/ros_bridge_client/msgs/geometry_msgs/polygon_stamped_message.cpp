//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/polygon_stamped_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

PolygonStampedMessage::PolygonStampedMessage(std::string frame_id)
  : PolygonMessage("polygon"),
    ros_msg_type("geometry_msgs/PolygonStamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}


PolygonStampedMessage::PolygonStampedMessage(const ros_bridge_client::ros_types::Point32 &point, std::string frame_id)
  : PolygonMessage("polygon"),
    ros_msg_type("geometry_msgs/PolygonStamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
  add(point);
}


json::value PolygonStampedMessage::createJsonMsg() const
{
  json::value geometry_msgs_json;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_message(frame_id);
  geometry_msgs_json[U("header")] = header_message.getJsonAt("msg");
  geometry_msgs_json[U(array_descriptor)] = MessageBase::getJsonAt("msg").array();

  return geometry_msgs_json;
}
