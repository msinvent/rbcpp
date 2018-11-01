//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/int8_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int8Message::Int8Message(int8_t data)
  : StdMessage<int8_t>(data, "std_msgs/Int8")
{}
