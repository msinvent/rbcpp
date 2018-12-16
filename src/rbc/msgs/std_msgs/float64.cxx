//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/float64.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

Float64::Float64()
  : StdMsg("std_msgs/Float64")
{}

Float64::Float64(double data)
    : StdMsg(data, "std_msgs/Float64")
{}

Float64::Float64(const web::json::value &response)
    : StdMsg("std_msgs/Float64")
{
  utils::Deserializer::deserialize<double>(*this, response);
}

