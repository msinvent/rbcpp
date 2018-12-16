//
// Created by julian on 18.11.18.
//

#include <rbc/msgs/std_msgs/float32.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

Float32::Float32()
  : StdMsg("std_msgs/Float32")
{}

Float32::Float32(float data)
    : StdMsg(data, "std_msgs/Float32")
{}

Float32::Float32(const web::json::value &response)
    : StdMsg("std_msgs/Float32")
{
  utils::Deserializer::deserialize<float>(*this, response, false);
}

