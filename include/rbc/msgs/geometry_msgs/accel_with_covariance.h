//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_ACCEL_WITH_COVARIANCE_HPP
#define ROSBRIDGECLIENT_ACCEL_WITH_COVARIANCE_HPP

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/geometry_msgs/util/covariance.h>
#include <rbc/msgs/geometry_msgs/accel.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct AccelWithCovariance : public ROSTypeBase
{
  explicit AccelWithCovariance();

  AccelWithCovariance(double lx, double ly, double lz, double ax, double ay, double az,
                      const std::array<double, 36> &covariance);

  AccelWithCovariance(const Vector3 &linear, const Vector3 &angular, const std::array<double, 36> &covariance);
  
  AccelWithCovariance(const Accel &accel, const std::array<double, 36> &covariance);

  explicit AccelWithCovariance(const web::json::value &response);

  ~AccelWithCovariance() override = default;

  Accel accel;
  std::array<double, 36> covariance;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::AccelWithCovariance &a);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::AccelWithCovariance> &a);

#endif //ROSBRIDGECLIENT_ACCEL_WITH_COVARIANCE_HPP