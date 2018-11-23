//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_FLOAT32_H
#define ROSBRIDGECLIENT_FLOAT32_H

#include <ros_bridge_client/msgs/std_msgs/std_msg.h>

namespace ros_bridge_client::msgs::std_msgs
{

struct Float32 : public StdMsg<float>
{
  Float32();

  explicit Float32(float data);

  ~Float32() final = default;
};

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_FLOAT32_H
