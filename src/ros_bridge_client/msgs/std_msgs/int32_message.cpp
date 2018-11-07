//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/int32_message.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int32Message::Int32Message(int32_t data)
  : StdMessage<int32_t>(data, "std_msgs/Int32")
{}
