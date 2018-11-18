//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint32.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt32::UInt32()
  : StdMsg("std_msgs/UInt32")
{}

UInt32::UInt32(uint32_t data)
    : StdMsg(data, "std_msgs/UInt32")
{}

