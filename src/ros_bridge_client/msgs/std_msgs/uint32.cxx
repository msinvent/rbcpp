//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint32.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt32::UInt32()
    : StdMsg("std_msgs/UInt32")
{}

UInt32::UInt32(uint32_t data)
    : StdMsg(data, "std_msgs/UInt32")
{}

UInt32::UInt32(const web::json::value &response)
    : StdMsg(data, "std_msgs/UInt32")
{
  utils::Deserializer::toStdMsg<uint32_t>(*this, response);
}

