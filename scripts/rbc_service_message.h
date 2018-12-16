//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_RBC_SERVICE_MESSAGE_HPP
#define ROSBRIDGECLIENT_RBC_SERVICE_MESSAGE_HPP

#include <rbc/msgs/message_base.h>

namespace rbc::msgs::std_msgs
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
} // namespace rbc::msgs::std_msgs


#endif //ROSBRIDGECLIENT_RBC_SERVICE_MESSAGE_HPP