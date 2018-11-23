//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/float32.h>

using namespace ros_bridge_client::msgs::std_msgs;

Float32::Float32()
  : StdMsg("std_msgs/Float32")
{}

Float32::Float32(float data)
    : StdMsg(data, "std_msgs/Float32")
{}

