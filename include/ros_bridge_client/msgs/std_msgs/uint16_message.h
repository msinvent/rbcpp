//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_U_INT16_MESSAGE_H
#define ROSBRIDGECLIENT_U_INT16_MESSAGE_H

#include <ros_bridge_client/msgs/std_msgs/std_message.h>
#include <tiff.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class UInt16Message : public StdMessage<uint16_t>
{
public:
  UInt16Message() = delete;

  explicit UInt16Message(uint16_t data);

  ~UInt16Message() final = default;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_UINT32_MESSAGE_H