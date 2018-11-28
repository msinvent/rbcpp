//
// Created by julian on 28.11.18.
//

#ifndef ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_H
#define ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_H

#include <ros_bridge_client/msgs/ros_type_base.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist.h>
#include <array>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct TwistWithCovariance : public ROSTypeBase
{
  TwistWithCovariance();
  TwistWithCovariance(const TwistWithCovariance &twist_cov);
  TwistWithCovariance(const Vector3& linear, const Vector3 &angular, std::array<double, 36> covariance);
  TwistWithCovariance(const Twist &twist, std::array<double, 36> covariance);
  ~TwistWithCovariance() final = default;
  Twist twist;
  std::array<double, 36> covariance;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

#endif //ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_H
