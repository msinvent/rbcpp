//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint16.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt16::UInt16()
  : StdMsg("std_msgs/UInt16")
{}

UInt16::UInt16(uint16_t data)
    : StdMsg(data, "std_msgs/UInt16")
{}

