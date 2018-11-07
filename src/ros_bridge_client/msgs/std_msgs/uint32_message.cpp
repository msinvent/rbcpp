//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint32_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt32Message::UInt32Message(uint32_t data)
  : StdMessage<uint32_t>(data, "std_msgs/UInt32")
{}
