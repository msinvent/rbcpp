//
// Created by Julian on 20.10.18.
//

#include <ros_bridge_client/msgs/message_base.h>
#include <cpprest/ws_client.h>

using namespace ros_bridge_client::msgs;

MessageBase::MessageBase(std::string ros_msg_type)
  : ros_msg_type(ros_msg_type)
{}

const std::string &MessageBase::rosMsgType() const
{
  return ros_msg_type;
}

MessageBase::MessageBase()
  : ros_msg_type("std_msgs/String")
{}
