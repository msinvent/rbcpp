//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/int32.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

Int32::Int32()
    : StdMsg("std_msgs/Int32")
{}

Int32::Int32(int32_t data)
    : StdMsg(data, "std_msgs/Int32")
{}

Int32::Int32(const web::json::value &response)
    : StdMsg("std_msgs/Int32")
{
  utils::Deserializer::deserialize<int32_t>(*this, response);
}

