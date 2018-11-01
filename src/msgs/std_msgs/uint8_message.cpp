//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint8_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt8Message::UInt8Message(uint8_t data)
  : StdMessage<uint8_t>(data, "std_msgs/UInt8")
{}
