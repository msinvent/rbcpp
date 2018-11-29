//
// Created by julian on 29.11.18.
//

#ifndef ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_STAMPED_H
#define ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_STAMPED_H

#include <ros_bridge_client/msgs/ros_type_base.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/utils/covariance.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct TwistWithCovarianceStamped : public ROSTypeBase
{
  explicit TwistWithCovarianceStamped(std::string frame_id = "world");
  TwistWithCovarianceStamped(const Vector3 &linear, const Vector3& angular,
                             const std::array<double, 36> &covariance, std::string frame_id);
  TwistWithCovarianceStamped(const Twist &twist, const std::array<double, 36> &covariance, std::string frame_id);
  TwistWithCovarianceStamped(const Vector3 &linear, const Vector3& angular,
                             const geometry_msgs::Covariance<double, 36> &covariance, std::string frame_id);
  TwistWithCovarianceStamped(const Twist &twist, const geometry_msgs::Covariance<double, 36> &covariance,
                             std::string frame_id);
  TwistWithCovarianceStamped(const TwistWithCovariance &twist_cov, std::string frame_id);
  ~TwistWithCovarianceStamped() final = default;

  TwistWithCovariance twist;
  std_msgs::Header header;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

#endif //ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_STAMPED_H
