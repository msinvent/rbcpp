//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_INT8_MESSAGE_H
#define ROSBRIDGECLIENT_INT8_MESSAGE_H

#include <ros_bridge_client/msgs/std_msgs/std_message.h>
#include <tiff.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class Int8Message : public StdMessage<int8_t>
{
public:
  Int8Message() = delete;

  explicit Int8Message(int8_t data);

  ~Int8Message() final = default;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_UINT32_MESSAGE_H