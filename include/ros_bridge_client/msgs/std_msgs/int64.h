//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_INT_H
#define ROSBRIDGECLIENT_INT_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct Int64 : public StdMsg<int64_t>
{
  Int64();

  explicit Int64(int64_t data);

  ~Int64() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_INT_H
