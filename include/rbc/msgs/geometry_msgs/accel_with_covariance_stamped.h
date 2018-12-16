//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_ACCEL_WITH_COVARIANCE_STAMPED_HPP
#define ROSBRIDGECLIENT_ACCEL_WITH_COVARIANCE_STAMPED_HPP

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/accel_with_covariance.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct AccelWithCovarianceStamped : public ROSTypeBase
{
  explicit AccelWithCovarianceStamped();

  AccelWithCovarianceStamped(const Vector3 &linear, const Vector3 &angular, const std::array<double, 36> &covariance,
                             std::string frame_id);

  AccelWithCovarianceStamped(const Accel &accel, const std::array<double, 36> &covariance, std::string frame_id);

  AccelWithCovarianceStamped(const AccelWithCovariance &accel_cov, std::string frame_id);

  explicit AccelWithCovarianceStamped(const web::json::value &response);

  ~AccelWithCovarianceStamped() override = default;

  AccelWithCovariance accel;
  std_msgs::Header header;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::AccelWithCovarianceStamped &a);

std::ostream &
operator<<(std::ostream &os,
           const std::shared_ptr<rbc::msgs::geometry_msgs::AccelWithCovarianceStamped> &a);

#endif //ROSBRIDGECLIENT_ACCEL_WITH_COVARIANCE_STAMPED_HPP