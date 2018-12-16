//
// Created by Julian on 15.10.18.
//

#include <rbc/service/rbc_service.h>

using namespace rbc::service;
using namespace rbc::msgs::service;
using namespace web;

RBCService::RBCService(ROSBridgeClient &client, std::string service_name)
  : ws_client(client),
    service_name(service_name)
{}

void RBCService::call(ServiceMessage &msg) const
{
  msg.setServiceName(service_name);
  ws_client.send(msg);
}
