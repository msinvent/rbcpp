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

  explicit ServiceCallMessage(const T &srv_call);

  ~ServiceCallMessage() = default;

  std::string toString() const;

  const web::json::value& json() const;

private:
  web::json::value json_msg_;
  utils::Serializer serializer;
};

} // rbc::srv

#include <rbc/service/service_call_message_impl.h>

#endif //ROSBRIDGECLIENT_SERVICE_CALL_MESSAGE_H
