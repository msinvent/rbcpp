//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_INT16_MESSAGE_H
#define ROSBRIDGECLIENT_INT16_MESSAGE_H

#include <ros_bridge_client/msgs/std_msgs/std_message.h>
#include <tiff.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class Int16Message : public StdMessage<int16_t>
{
public:
  Int16Message() = delete;

  explicit Int16Message(int16_t data);

  ~Int16Message() final = default;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_UINT32_MESSAGE_H