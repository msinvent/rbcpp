//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/int16.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

Int16::Int16()
    : StdMsg("std_msgs/Int16")
{}

Int16::Int16(int16_t data)
    : StdMsg(data, "std_msgs/Int16")
{}

Int16::Int16(const web::json::value &response)
    : StdMsg("std_msgs/Int16")
{
  utils::Deserializer::deserialize<int16_t>(*this, response);
}

