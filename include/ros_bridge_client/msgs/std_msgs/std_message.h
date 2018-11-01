//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_U_INT32_MESSAGE_HPP
#define ROSBRIDGECLIENT_U_INT32_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_message.h>
#include <tiff.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

template<typename T>
class StdMessage : public RBCMessage
{
public:
  StdMessage() = delete;

  StdMessage(T data, std::string ros_msg_type);

  virtual ~StdMessage() = default;

private:
  const std::string ros_msg_type;
  const T data;

  web::json::value createJsonMsg() const final;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

using namespace ros_bridge_client::msgs::std_msgs;
using namespace web;

template<typename T>
StdMessage<T>::StdMessage(T data, std::string ros_msg_type)
  : ros_msg_type(ros_msg_type),
    data(data)
{
  json[U("type")] = json::value::string(ros_msg_type);
  json[U("msg")] = createJsonMsg();
}

template<typename T>
json::value StdMessage<T>::createJsonMsg() const
{
  json::value message_json;
  message_json[U("data")] = data;
  return message_json;
}

#endif //ROSBRIDGECLIENT_U_INT32_MESSAGE_HPP