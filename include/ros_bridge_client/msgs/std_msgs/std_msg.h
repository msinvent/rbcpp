//
// Created by julian on 17.11.18.
//

#ifndef ROSBRIDGECLIENT_STD_MSG_H
#define ROSBRIDGECLIENT_STD_MSG_H

#include <ros_bridge_client/msgs/message_base.h>

namespace ros_bridge_client::msgs::std_msgs
{

template <typename T>
struct StdMsg : public MessageBase
{
  explicit StdMsg(const T& data, std::string ros_msg_type);
  ~StdMsg() override = default;
  T data;

protected:
  explicit StdMsg(std::string ros_msg_type);
};

template<typename T>
StdMsg<T>::StdMsg(const T &data, std::string ros_msg_type)
  : MessageBase(ros_msg_type), data(data)
{}

template<typename T>
StdMsg<T>::StdMsg(std::string ros_msg_type)
  : MessageBase(ros_msg_type), data()
{}

} // namespace ros_bridge_client::msgs::std_msgs

#endif //ROSBRIDGECLIENT_STD_MSG_H
