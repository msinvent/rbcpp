//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/uint32.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

UInt32::UInt32()
    : StdMsg("std_msgs/UInt32")
{}

UInt32::UInt32(uint32_t data)
    : StdMsg(data, "std_msgs/UInt32")
{}

UInt32::UInt32(const web::json::value &response)
    : StdMsg(data, "std_msgs/UInt32")
{
  utils::Deserializer::deserialize<uint32_t>(*this, response);
}

