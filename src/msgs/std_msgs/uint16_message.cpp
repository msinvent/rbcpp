//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint16_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt16Message::UInt16Message(uint16_t data)
  : StdMessage<uint16_t>(data, "std_msgs/UInt16")
{}
