//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint8.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt8::UInt8()
  : StdMsg("std_msgs/UInt8")
{}

UInt8::UInt8(uint8_t data)
    : StdMsg(data, "std_msgs/UInt8")
{}

