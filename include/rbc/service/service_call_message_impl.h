//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_IMPL_H
#define ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_IMPL_H

#include <rbc/service/service_call_message.h>

using namespace rbc::srv;

template<typename T>
ServiceCallMessage<T>::ServiceCallMessage(const T &srv_call)
{
  json_msg_[U("op")] = web::json::value::string("call_service");
  json_msg_[U("service")] = web::json::value::string(srv_call.name);
  json_msg_[U("args")] = web::json::value::array(serializer.serializeSingles(srv_call.args));
}

template<typename T>
std::string ServiceCallMessage<T>::toString() const
{
  utility::stringstream_t stream;
  json_msg_.serialize(stream);
  return stream.str();
}

template <typename T>
const web::json::value& ServiceCallMessage<T>::json() const
{
  return json_msg_;
}

#endif //ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_IMPL_H
