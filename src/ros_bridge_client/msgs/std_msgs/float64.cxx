//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/float64.h>

using namespace ros_bridge_client::msgs::std_msgs;

Float64::Float64()
  : StdMsg("std_msgs/Float64")
{}

Float64::Float64(double data)
    : StdMsg(data, "std_msgs/Float64")
{}

