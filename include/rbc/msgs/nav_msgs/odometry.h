//
// Created by julian on 16.12.18.
//

#ifndef ROSBRIDGECLIENT_ODOMETRY_H
#define ROSBRIDGECLIENT_ODOMETRY_H

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/pose_with_covariance.h>
#include <rbc/msgs/geometry_msgs/twist_with_covariance.h>

namespace rbc::msgs::nav_msgs
{

struct Odometry : public ROSTypeBase
{
  Odometry();

  Odometry(std::string frame_id, std::string child_frame_id);

  Odometry(std::string child_frame_id, const std_msgs::Header &header, const geometry_msgs::PoseWithCovariance &pose,
           const geometry_msgs::TwistWithCovariance &twist);

  explicit Odometry(const web::json::value &response);

  ~Odometry() final = default;

  std::string child_frame_id;
  std_msgs::Header header;
  geometry_msgs::PoseWithCovariance pose;
  geometry_msgs::TwistWithCovariance twist;
};

} // namespace rbc::msgs::nav_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::nav_msgs::Odometry &p);

std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<rbc::msgs::nav_msgs::Odometry> &p);
#endif //ROSBRIDGECLIENT_ODOMETRY_H
