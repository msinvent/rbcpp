//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_XYZMESSAGE_H
#define ROSBRIDGECLIENT_XYZMESSAGE_H

#include <ros_bridge_client/msgs/message_base.h>
#include <iostream>

namespace ros_bridge_client::msgs
{

template<typename T>
struct XYZMessage : public MessageBase
{
  T x, y, z;

protected:
  XYZMessage() = delete;

  explicit XYZMessage(std::string ros_msg_type);

  XYZMessage(std::string ros_msg_type, T x, T y, T z);

  XYZMessage(const XYZMessage<T> &xyz);

  ~XYZMessage() override = default;
};

template<typename T>
XYZMessage<T>::XYZMessage(std::string ros_msg_type)
  : MessageBase(ros_msg_type), x(0), y(0), z(0)
{}

template<typename T>
XYZMessage<T>::XYZMessage(std::string ros_msg_type, T x, T y, T z)
  : MessageBase(ros_msg_type), x(x), y(y), z(z)
{}

template<typename T>
XYZMessage<T>::XYZMessage(const XYZMessage<T> &xyz)
  : MessageBase(xyz.rosMsgType()), x(xyz.x), y(xyz.y), z(xyz.z)
{}

} // namespace ros_bridge_client::msgs

#endif //ROSBRIDGECLIENT_XYZMESSAGE_H
