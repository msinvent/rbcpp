//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/int32.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

Int32::Int32()
    : StdMsg("std_msgs/Int32")
{}

Int32::Int32(int32_t data)
    : StdMsg(data, "std_msgs/Int32")
{}

Int32::Int32(const web::json::value &response)
    : StdMsg(data, "std_msgs/Int32")
{
  utils::Deserializer::toStdMsg<int32_t>(*this, response);
}

