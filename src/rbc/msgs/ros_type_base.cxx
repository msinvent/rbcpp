//
// Created by Julian on 20.10.18.
//

#include <rbc/msgs/ros_type_base.h>
#include <cpprest/ws_client.h>

using namespace rbc::msgs;

ROSTypeBase::ROSTypeBase(std::string ros_msg_type)
  : ros_msg_type(ros_msg_type)
{}

const std::string &ROSTypeBase::rosMsgType() const
{
  return ros_msg_type;
}
