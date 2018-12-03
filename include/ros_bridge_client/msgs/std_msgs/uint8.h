//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_UINT8_H
#define ROSBRIDGECLIENT_UINT8_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct UInt8 : public StdMsg<uint8_t>
{
  UInt8();

  explicit UInt8(uint8_t data);

  explicit UInt8(const web::json::value &response);

  ~UInt8() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_UINT8_H
