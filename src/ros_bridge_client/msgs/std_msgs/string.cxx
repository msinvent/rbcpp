//
// Created by julian on 17.11.18.
//

#include <rbc/msgs/std_msgs/string.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::std_msgs;

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


