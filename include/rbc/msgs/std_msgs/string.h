//
// Created by julian on 17.11.18.
//

#ifndef ROSBRIDGECLIENT_STRING_H
#define ROSBRIDGECLIENT_STRING_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct String : public StdMsg<std::string>
{
  String();
  explicit String(std::string str);
  explicit String(const web::json::value &response);
  ~String() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_STRING_H
