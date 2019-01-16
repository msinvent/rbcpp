//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/uint16.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

UInt16::UInt16()
    : StdMsg("std_msgs/UInt16")
{}

UInt16::UInt16(uint16_t data)
    : StdMsg(data, "std_msgs/UInt16")
{}

UInt16::UInt16(const web::json::value &response)
    : StdMsg("std_msgs/UInt16")
{
  utils::Deserializer::deserialize<uint16_t>(*this, response);
}

