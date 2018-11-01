//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_STRINGMESSAGE_HPP
#define ROSBRIDGECLIENT_STRINGMESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

class StringMessage : public RBCMessage
{
public:
  explicit StringMessage(const std::string data);

  explicit StringMessage(const web::json::value &msg);

  StringMessage() = delete;

  ~StringMessage() final = default;

private:
  const std::string data_;
  const std::string ros_type;

  web::json::value createJsonMsg() const final;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_STRINGMESSAGE_HPP
