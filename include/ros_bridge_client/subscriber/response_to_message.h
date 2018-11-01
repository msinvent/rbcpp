//
// Created by Julian on 15.10.18.
//

#ifndef ROSBRIDGECLIENT_RESPONSE_TO_MESSAGE_H
#define ROSBRIDGECLIENT_RESPONSE_TO_MESSAGE_H

#include <ros_bridge_client/msgs/rbc_subscribe_message.h>

using namespace ros_bridge_client::msgs;
using namespace web;

namespace ros_bridge_client
{
namespace subscriber
{
namespace conversions
{

static inline RBCSubscribeMessage
responseToMessage(std::string topic, std::string ros_msg_type, const web::json::value &response)
{
  RBCSubscribeMessage msg(topic, ros_msg_type, response.at("msg"));
  return msg;
}

} // namespace conversions
} // namespace subscriber
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_RESPONSE_TO_MESSAGE_H
