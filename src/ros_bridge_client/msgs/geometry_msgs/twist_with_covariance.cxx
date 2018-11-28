//
// Created by julian on 28.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

TwistWithCovariance::TwistWithCovariance()
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(),
    covariance()
{}

TwistWithCovariance::TwistWithCovariance(const Vector3 &linear, const Vector3 &angular,
                                         std::array<double, 36> covariance)
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(linear, angular),
    covariance(covariance)
{}

TwistWithCovariance::TwistWithCovariance(const Twist &twist, std::array<double, 36> covariance)
  : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
    twist(twist),
    covariance(covariance)
{}

TwistWithCovariance::TwistWithCovariance(const TwistWithCovariance &twist_cov)
    : ROSTypeBase("geometry_msgs/TwistWithCovariance"),
      twist(twist_cov.twist),
      covariance(twist_cov.covariance)
{}
