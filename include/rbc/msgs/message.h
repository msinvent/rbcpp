//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_MESSAGE_H
#define ROSBRIDGECLIENT_MESSAGE_H

#include <cpprest/json.h>
#include <rbc/utils/serializer.h>

namespace rbc::msgs
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

} // namespace rbc::msgs

#include <rbc/msgs/message_impl.h>

#endif //ROSBRIDGECLIENT_MESSAGE_H
