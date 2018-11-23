//
// Created by julian on 18.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/float32.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::std_msgs;

Float32::Float32()
  : StdMsg("std_msgs/Float32")
{}

Float32::Float32(float data)
    : StdMsg(data, "std_msgs/Float32")
{}

Float32::Float32(const web::json::value &response)
    : StdMsg("std_msgs/Float32")
{
  data = utils::ResponseConverter::responseToStdMsg<float>(response);
}

