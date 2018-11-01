//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_U_INT64_MESSAGE_H
#define ROSBRIDGECLIENT_U_INT64_MESSAGE_H

#include <ros_bridge_client/msgs/std_msgs/std_message.h>
#include <tiff.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class UInt64Message : public StdMessage<uint64_t>
{
public:
  UInt64Message() = delete;

  explicit UInt64Message(uint64_t data);

  ~UInt64Message() final = default;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_UINT32_MESSAGE_H