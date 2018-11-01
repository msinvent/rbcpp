//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint64_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt64Message::UInt64Message(uint64_t data)
  : StdMessage<uint64_t>(data, "std_msgs/UInt64")
{}
