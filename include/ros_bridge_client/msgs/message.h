//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_MESSAGE_H
#define ROSBRIDGECLIENT_MESSAGE_H

#include <cpprest/json.h>
#include <ros_bridge_client/utils/serializer.h>

namespace ros_bridge_client::msgs
{

template<typename T>
class Message
{
public:
  Message() = delete;

  explicit Message(const T &data);

  ~Message() = default;

  void setTopic(std::string topic);

  std::string toString() const;

private:
  utils::Serializer json_creator_;
  const T &data_;
  web::json::value &json_msg_;
};

} // namespace ros_bridge_client::msgs

#include <ros_bridge_client/msgs/message_impl.h>

#endif //ROSBRIDGECLIENT_MESSAGE_H
