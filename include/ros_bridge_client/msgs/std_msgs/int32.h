//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_INT32_H
#define ROSBRIDGECLIENT_INT32_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct Int32 : public StdMsg<int32_t>
{
  Int32();

  explicit Int32(int32_t data);

  ~Int32() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_INT32_H
