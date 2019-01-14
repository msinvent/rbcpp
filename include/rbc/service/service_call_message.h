//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_H
#define ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_H

#include <cpprest/json.h>
#include <rbc/utils/serializer.h>
#include <rbc/service/service_call.h>

namespace rbc::srv
{

template<typename T>
struct ServiceCallMessage
{
  ServiceCallMessage() = delete;

  explicit ServiceCallMessage(const ServiceCall<T> &srv_call);

  ~ServiceCallMessage() = default;

  std::string toString() const;
  
  web::json::value json_msg_;
  utils::Serializer serializer;
};

template<typename T>
ServiceCallMessage<T>::ServiceCallMessage(const ServiceCall<T> &srv_call)
{
  json_msg_[U("op")] = web::json::value::string("call_service");
  json_msg_[U("srv")] = web::json::value::string(srv_call.name);
  json_msg_[U("args")] = web::json::value::array(serializer.serializeSingles<T>(srv_call.args));
}

template<typename T>
std::string ServiceCallMessage<T>::toString() const
{
  utility::stringstream_t stream;
  json_msg_.serialize(stream);
  return stream.str();
}

} // rbc::srv

#endif //ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_H
