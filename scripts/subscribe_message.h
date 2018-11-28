//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_SUBSCRIBE_MESSAGE_HPP
#define ROSBRIDGECLIENT_SUBSCRIBE_MESSAGE_HPP

#include <ros_bridge_client/msgs/message_base.h>

namespace ros_bridge_client::msgs::std_msgs
{

class SubscribeMessage : public RBCMessage
{
public:
  SubscribeMessage();
  ~SubscribeMessage() final = default;

private:
  const std::string ros_msg_type;
  web::json::value createJsonMsg() const final;
};
} // namespace ros_bridge_client::msgs::std_msgs


#endif //ROSBRIDGECLIENT_SUBSCRIBE_MESSAGE_HPP