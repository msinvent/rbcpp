//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_STAMPED_H
#define ROSBRIDGECLIENT_POSE_STAMPED_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/message_base.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct PoseStamped : public MessageBase
{
  PoseStamped();

  PoseStamped(const Pose &pose, std::string frame_id);

  PoseStamped(double x, double y, double z, double xx, double yy, double zz, double ww, std::string frame_id);
  
  explicit PoseStamped(const web::json::value &response);
  
  ~PoseStamped() override = default;
  
  std_msgs::Header header;
  Pose pose;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::PoseStamped &p);

std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::PoseStamped> &p);

#endif //ROSBRIDGECLIENT_POSE_STAMPED_H
