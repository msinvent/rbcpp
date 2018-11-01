//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/twist_stamped_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

TwistStampedMessage::TwistStampedMessage(const ros_types::Vector3 &linear,
                                         const ros_types::Vector3 &angular, std::string frame_id)
  : TwistMessage(linear, angular),
    ros_msg_type("geometry_msgs/TwistStamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}


TwistStampedMessage::TwistStampedMessage(double lx, double ly, double lz, double ax, double ay, double az,
                                         std::string frame_id)
  : TwistMessage(lx, ly, lz, ax, ay, az),
    ros_msg_type("geometry_msgs/TwistStamped"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value TwistStampedMessage::createJsonMsg() const
{
  json::value json_twist_stamped;

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header_msg(frame_id);

  json_twist_stamped[U("header")] = header_msg.getJsonAt("msg");

  // twist is AccelStampedMessage field msg: set in parents AccelStampedMessage constructor
  json_twist_stamped[U("twist")] = RBCMessage::getJsonAt("msg");

  return json_twist_stamped;
}
