//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_INT8_H
#define ROSBRIDGECLIENT_INT8_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct Int8 : public StdMsg<int8_t>
{
  Int8();

  explicit Int8(int8_t data);

  explicit Int8(const web::json::value &response);

  ~Int8() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_INT8_H
