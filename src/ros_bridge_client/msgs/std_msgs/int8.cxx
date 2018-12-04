//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/int8.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int8::Int8()
  : StdMsg("std_msgs/Int8")
{}

Int8::Int8(int8_t data)
    : StdMsg(data, "std_msgs/Int8")
{}

Int8::Int8(const web::json::value &response)
    : StdMsg(data, "std_msgs/Int8")
{
  utils::Deserializer::toStdMsg<int8_t>(*this, response);
}
