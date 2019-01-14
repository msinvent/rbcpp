//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICE_LISTENER_IMPL_H
#define ROSBRIDGECLIENT_SERVICE_LISTENER_IMPL_H

#include <rbc/service/service_handler.h>
#include <rbc/service/service_call_message.h>

using namespace rbc::srv;

template<typename T>
ServiceHandler<T>::ServiceHandler(std::shared_ptr<ROSBridgeClient> rbc, std::string service_name,
                                  std::string response_name,
                                  std::function<void(std::shared_ptr<T>)> cb)
    : rbc(rbc), received_msg(nullptr), service_name(service_name), response_name(response_name), callback(cb)
{
  rbc->log.log("Listening to Service ", service_name);
}

template<typename T>
ServiceHandler<T>::~ServiceHandler()
{
  rbc->log.log("Unlistening from service ", service_name);
}

template<typename T>
void ServiceHandler<T>::addResponse(const web::json::value &msg)
{
  received_msg = std::make_shared<T>(msg, response_name);
  callback(received_msg);
}

template<typename T>
void ServiceHandler<T>::callService(const T &srv_call)
{
  if (service_name != srv_call.name)
  {
    std::cerr << "Trying to call service '" << srv_call.name << "' on ServiceHandler for service '" << service_name
              << "'\n";
    return;
  }

  ServiceCallMessage<T> msg(srv_call);
  rbc->send(msg.json());
}

#endif //ROSBRIDGECLIENT_SERVICE_LISTENER_IMPL_H
