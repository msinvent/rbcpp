//
// Created by julian on 29.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance_stamped.h>
#include "ros_bridge_client/msgs/geometry_msgs/twist_with_covariance_stamped.h"


using namespace ros_bridge_client::msgs::geometry_msgs;

TwistWithCovarianceStamped::TwistWithCovarianceStamped(std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const TwistWithCovariance &twist_cov, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(twist_cov),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const Twist &twist, const std::array<double, 36> &covariance,
                                                       std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(twist, covariance),
    header(frame_id)
{}

TwistWithCovarianceStamped::TwistWithCovarianceStamped(const Vector3 &linear, const Vector3 &angular,
                                                       const std::array<double, 36> &covariance, std::string frame_id)
  : ROSTypeBase("geometry_msgs/TwistWithCovarianceStamped"),
    twist(linear, angular, covariance),
    header(frame_id)
{}
