//
// Created by julian on 28.11.18.
//

#ifndef ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_H
#define ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_H

#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/geometry_msgs/twist.h>
#include <rbc/msgs/geometry_msgs/util/covariance.h>
#include <array>

namespace rbc::msgs::geometry_msgs
{

struct TwistWithCovariance : public ROSTypeBase
{
  TwistWithCovariance();

  explicit TwistWithCovariance(const web::json::value &response);
  TwistWithCovariance(const TwistWithCovariance &twist_cov);
  TwistWithCovariance(const Vector3& linear, const Vector3 &angular, std::array<double, 36> cov);
  TwistWithCovariance(const Twist &twist, std::array<double, 36> cov);
  ~TwistWithCovariance() final = default;
  Twist twist;
  std::array<double, 36> covariance;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::TwistWithCovariance &t);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::TwistWithCovariance> &t);

#endif //ROSBRIDGECLIENT_TWIST_WITH_COVARIANCE_H
