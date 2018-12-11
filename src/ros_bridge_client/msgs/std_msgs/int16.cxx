//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/int16.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int16::Int16()
    : StdMsg("std_msgs/Int16")
{}

Int16::Int16(int16_t data)
    : StdMsg(data, "std_msgs/Int16")
{}

Int16::Int16(const web::json::value &response)
    : StdMsg(data, "std_msgs/Int16")
{
  utils::Deserializer::deserialize<int16_t>(*this, response);
}

