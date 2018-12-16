//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_WITH_COVARIANCE_H
#define ROSBRIDGECLIENT_POSE_WITH_COVARIANCE_H

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/geometry_msgs/pose.h>
#include <rbc/msgs/geometry_msgs/util/covariance.h>

namespace rbc::msgs::geometry_msgs
{

struct PoseWithCovariance : public ROSTypeBase
{
  PoseWithCovariance();

  PoseWithCovariance(double x, double y, double z, double xx, double yy, double zz, double ww,
                     const std::array<double, 36> &arr);

  PoseWithCovariance(const Point &p, const Quaternion &q, const std::array<double, 36> &arr);

  PoseWithCovariance(const Pose &pose, const std::array<double, 36> &arr);

  explicit PoseWithCovariance(const web::json::value &response);

  ~PoseWithCovariance() final = default;

  Pose pose;
  std::array<double, 36> covariance;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::PoseWithCovariance &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::PoseWithCovariance> &p);

#endif //ROSBRIDGECLIENT_POSE_WITH_COVARIANCE_H
