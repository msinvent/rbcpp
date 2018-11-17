//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_RBC_SUBSCRIBE_MESSAGE_HPP
#define ROSBRIDGECLIENT_RBC_SUBSCRIBE_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>

namespace ros_bridge_client::msgs
{

class RBCSubscribeMessage : public RBCMessage
{
public:
  RBCSubscribeMessage();

  RBCSubscribeMessage(std::string topic, std::string ros_msg_type, const web::json::value &msg);

  ~RBCSubscribeMessage() final = default;
};

} // namespace ros_bridge_client::msgs


#endif //ROSBRIDGECLIENT_RBC_SUBSCRIBE_MESSAGE_HPP