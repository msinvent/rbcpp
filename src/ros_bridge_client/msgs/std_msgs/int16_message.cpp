//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/int16_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int16Message::Int16Message(int16_t data)
  : StdMessage<int16_t>(data, "std_msgs/Int16")
{}
