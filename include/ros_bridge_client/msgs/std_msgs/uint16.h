//
// Created by julian on 116.11.116.
//

#ifndef ROSBRIDGECLIENT_UINT16_H
#define ROSBRIDGECLIENT_UINT16_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct UInt16 : public StdMsg<uint16_t>
{
  UInt16();

  explicit UInt16(uint16_t data);

  ~UInt16() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_UINT16_H
