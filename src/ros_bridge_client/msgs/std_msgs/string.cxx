//
// Created by julian on 17.11.18.
//

#include <ros_bridge_client/msgs/std_msgs/string.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;

String::String()
  : StdMsg<std::string>("std_msgs/String")
{}

String::String(std::string str)
  : StdMsg<std::string>(str, "std_msgs/String")
{}

String::String(const web::json::value &response)
  : StdMsg<std::string>("std_msgs/String")
{
  utils::Deserializer::deserialize(data, response, false);
}


