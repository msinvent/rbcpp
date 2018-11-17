//
// Created by julian on 17.11.18.
//

#ifndef ROSBRIDGECLIENT_STRING_H
#define ROSBRIDGECLIENT_STRING_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct String : public StdMsg<std::string>
{
  String();
  explicit String(std::string str);
  explicit String(const web::json::value &response);
  ~String() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_STRING_H
