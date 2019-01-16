//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/uint64.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

UInt64::UInt64()
    : StdMsg("std_msgs/UInt64")
{}

UInt64::UInt64(uint64_t data)
    : StdMsg(data, "std_msgs/UInt64")
{}

UInt64::UInt64(const web::json::value &response)
    : StdMsg("std_msgs/UInt64")
{
  utils::Deserializer::deserialize<uint64_t>(*this, response);
}

