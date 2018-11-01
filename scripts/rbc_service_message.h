//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_RBC_SERVICE_MESSAGE_HPP
#define ROSBRIDGECLIENT_RBC_SERVICE_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>

namespace ros_bridge_client::msgs::std_msgs
{

class RBCServiceMessage : public RBCMessage
{
public:
  RBCServiceMessage();
  ~RBCServiceMessage() final = default;

private:
  const std::string ros_msg_type;
  web::json::value createJsonMsg() const final;
};
} // namespace ros_bridge_client::msgs::std_msgs


#endif //ROSBRIDGECLIENT_RBC_SERVICE_MESSAGE_HPP