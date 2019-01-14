//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICE_CALL_H
#define ROSBRIDGECLIENT_SERVICE_CALL_H

#include <string>
#include <vector>
#include <cpprest/json.h>

namespace rbc::srv
{

template <typename T>
struct ServiceCall
{
  ServiceCall() = delete;

  ServiceCall(std::string name, const std::vector<T> &args);

  ServiceCall(const web::json::value &response, std::string response_name);

  ~ServiceCall() = default;

  std::string name;
  std::vector<T> args;
};

template<typename T>
ServiceCall<T>::ServiceCall(std::string name, const std::vector<T> &args)
  : name(name), args(args)
{}

template<typename T>
ServiceCall<T>::ServiceCall(const web::json::value &response, std::string response_name)
{
}

} // namespace rbc::srv

#endif //ROSBRIDGECLIENT_SERVICE_CALL_H
