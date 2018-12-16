//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_STAMPED_H
#define ROSBRIDGECLIENT_POSE_STAMPED_H

#include <cpprest/json.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/pose.h>
#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::geometry_msgs
{

struct PoseStamped : public ROSTypeBase
{
  PoseStamped();

  PoseStamped(const Pose &pose, std::string frame_id);

  PoseStamped(double x, double y, double z, double xx, double yy, double zz, double ww, std::string frame_id);
  
  explicit PoseStamped(const web::json::value &response);
  
  ~PoseStamped() override = default;
  
  std_msgs::Header header;
  Pose pose;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::PoseStamped &p);

std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<rbc::msgs::geometry_msgs::PoseStamped> &p);

#endif //ROSBRIDGECLIENT_POSE_STAMPED_H
