//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint64.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt64::UInt64()
    : StdMsg("std_msgs/UInt64")
{}

UInt64::UInt64(uint64_t data)
    : StdMsg(data, "std_msgs/UInt64")
{}

UInt64::UInt64(const web::json::value &response)
    : StdMsg(data, "std_msgs/UInt64")
{
  utils::Deserializer::toStdMsg<uint64_t>(*this, response);
}

