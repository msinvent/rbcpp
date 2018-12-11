//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/uint8.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

UInt8::UInt8()
    : StdMsg("std_msgs/UInt8")
{}

UInt8::UInt8(uint8_t data)
    : StdMsg(data, "std_msgs/UInt8")
{}

UInt8::UInt8(const web::json::value &response)
    : StdMsg(data, "std_msgs/UInt8")
{
  utils::Deserializer::deserialize<uint8_t>(*this, response);
}

