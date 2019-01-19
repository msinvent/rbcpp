//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICE_CALL_IMPL_H
#define ROSBRIDGECLIENT_SERVICE_CALL_IMPL_H

#include <rbc/service/service_call.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::srv;

template<typename T>
ServiceCall<T>::ServiceCall(std::string name, const std::vector<T> &args)
    : name(name), args(args), response()
{}

template<typename T>
ServiceCall<T>::ServiceCall(const web::json::value &response_json, std::string response_name)
    : name(), args(), response()
{
  const auto &msg = response_json.at(U("values"));
  name = response_json.at(U("service")).as_string();

  // checks if response is from service not being online
  try
  {
    const auto &resp_str = msg.as_string();
    if (resp_str.find("does not exist") != resp_str.npos)
    {
      std::cerr << "Your service server is not online! returning\n";
      return;
    }
  }
  catch (const std::exception &e) // just as an example: because msg.as_string() can fail when receiving a double
  // we now know it must be from service and the desired value
  {
    // tries to get value from service response
    try
    {
      response = static_cast<T>(msg.at(U(response_name)).as_double());
    }
    catch (std::exception &e)
    {
      std::cerr << "Can't get service response: " << e.what() << "\n";
      std::cerr << "Are you calling service too often? ros_bridge doesn't like that\n";
      response = -1000;
    }
  }

}

#endif //ROSBRIDGECLIENT_SERVICE_CALL_IMPL_H
