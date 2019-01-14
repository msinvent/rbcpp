//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICERESPONSELISTENER_H
#define ROSBRIDGECLIENT_SERVICERESPONSELISTENER_H

#include <cpprest/json.h>
#include <rbc/ros_bridge_client.h>
#include <rbc/service/service_handler_base.h>

namespace rbc::srv
{

template <typename T>
struct ServiceHandler : public ServiceHandlerBase
{
  ServiceHandler() = delete;

  ServiceHandler(std::shared_ptr<ROSBridgeClient> rbc, std::string service_name, std::string response_name, std::function<void(std::shared_ptr<T>)> cb);

  ~ServiceHandler() final;
  
  void addResponse(const web::json::value &msg) final;
  
  void callService(const T &srv_call);
  
private:
  std::shared_ptr<ROSBridgeClient> rbc;
  std::shared_ptr<T> received_msg;
  std::string service_name;
  std::string response_name;
  std::function<void(std::shared_ptr<T>)> callback;
};


} // namespace rbc::srv

#include <rbc/service/service_handler_impl.h>

#endif //ROSBRIDGECLIENT_SERVICERESPONSELISTENER_H
