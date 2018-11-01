//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/int64_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int64Message::Int64Message(int64_t data)
  : StdMessage<int64_t>(data, "std_msgs/Int64")
{}
