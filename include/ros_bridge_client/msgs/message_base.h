//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_MESSAGE_BASE_H
#define ROSBRIDGECLIENT_MESSAGE_BASE_H

#include <string>

namespace ros_bridge_client
{

namespace msgs
{

struct MessageBase
{
  MessageBase() = delete;

  virtual ~MessageBase() = default;

  const std::string &rosMsgType() const;

protected:
  explicit MessageBase(std::string ros_msg_type);

private:
  const std::string ros_msg_type;

};


} // msgs
} // ros_bridge_client


#endif //ROSBRIDGECLIENT_MESSAGE_BASE_H
