//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/int64.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

Int64::Int64()
  : StdMsg("std_msgs/Int64")
{}

Int64::Int64(int64_t data)
    : StdMsg(data, "std_msgs/Int64")
{}

Int64::Int64(const web::json::value &response)
    : StdMsg("std_msgs/Int64")
{
  utils::Deserializer::deserialize<int64_t>(*this, response);
}

