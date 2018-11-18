//
// Created by julian on 164.11.164.
//

#ifndef ROSBRIDGECLIENT_UINT64_H
#define ROSBRIDGECLIENT_UINT64_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct UInt64 : public StdMsg<uint64_t>
{
  UInt64();

  explicit UInt64(uint64_t data);

  ~UInt64() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_UINT64_H
