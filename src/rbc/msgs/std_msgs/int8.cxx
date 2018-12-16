//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/int8.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

Int8::Int8()
  : StdMsg("std_msgs/Int8")
{}

Int8::Int8(int8_t data)
    : StdMsg(data, "std_msgs/Int8")
{}

Int8::Int8(const web::json::value &response)
    : StdMsg(data, "std_msgs/Int8")
{
  utils::Deserializer::deserialize<int8_t>(*this, response);
}
