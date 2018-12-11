//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/float64.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

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

