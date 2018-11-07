//
// Created by Julian
//
#include <ros_bridge_client/msgs/geometry_msgs/pose_message.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_array_message.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

using namespace ros_bridge_client::msgs::geometry_msgs;
using namespace web;

PoseArrayMessage::PoseArrayMessage(std::string frame_id)
  : RBCArrayMessage("poses"),
    ros_msg_type("geometry_msgs/PoseArray"),
    frame_id(frame_id)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

json::value PoseArrayMessage::createJsonMsg() const
{
  json::value pose_array_json = RBCMessage::getJsonAt("msg");

  using namespace ros_bridge_client::msgs::std_msgs;
  Header header(frame_id);
  pose_array_json[U("header")] = header.getJsonAt("msg");

  return pose_array_json;
}

void PoseArrayMessage::add(const ros_types::Pose &pose)
{
  using namespace ros_bridge_client::msgs::geometry_msgs;
  PoseMessage pose_message(pose);

  auto &current_cells = json.at(U("msg")).at(U("poses")).as_array();
  current_cells[next_index()] = pose_message.getJsonAt("msg");
}

void PoseArrayMessage::add(float x, float y, float z, float xx, float yy, float zz, float ww)
{
  ros_types::Pose pose;
  pose.p.x = x;
  pose.p.y = y;
  pose.p.z = z;
  pose.q.x = xx;
  pose.q.y = yy;
  pose.q.z = zz;
  pose.q.w = ww;
  add(pose);
}
