//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_U_INT8_MESSAGE_H
#define ROSBRIDGECLIENT_U_INT8_MESSAGE_H

#include <ros_bridge_client/msgs/std_msgs/std_message.h>
#include <tiff.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class UInt8Message : public StdMessage<uint8_t>
{
public:
  UInt8Message() = delete;

  explicit UInt8Message(uint8_t data);

  ~UInt8Message() final = default;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_UINT32_MESSAGE_H