//
// Created by Julian
//

#include <ros_bridge_client/msgs/geometry_msgs/pose_2d_message.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

Pose2DMessage::Pose2DMessage(double x, double y, double theta)
  : ros_msg_type("geometry_msgs/Pose2D")
{
  pose_2d.x = x;
  pose_2d.y = y;
  pose_2d.theta = theta;

  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

Pose2DMessage::Pose2DMessage(const ros_bridge_client::ros_types::Pose2D &p2d)
  : ros_msg_type("geometry_msgs/Pose2D")
{
  pose_2d = p2d;

  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value Pose2DMessage::createJsonMsg() const
{
  json::value json_point;
  json_point[U("x")] = pose_2d.x;
  json_point[U("y")] = pose_2d.y;
  json_point[U("theta")] = pose_2d.theta;
  return json_point;
}
