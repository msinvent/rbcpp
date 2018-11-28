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
