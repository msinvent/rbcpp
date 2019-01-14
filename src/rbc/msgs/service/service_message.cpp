//
// Created by Julian
//

#include <rbc/msgs/service/service_message.h>

using namespace rbc::msgs::service;
using namespace web;

ServiceMessage::ServiceMessage()
  : RBCArrayMessage(ServiceDef())
{}

ServiceMessage::ServiceMessage(const std::vector<std::string> &args)
  : RBCArrayMessage(ServiceDef())
{
  setArgs(args);
}

void ServiceMessage::setServiceName(const std::string &service_name)
{
  json[U("srv")] = json::value::string(service_name);
}

void ServiceMessage::setArgs(const std::vector<std::string> &args)
{
  auto &current_cells = json.at(U("args")).as_array();
  for (const auto &arg: args)
  {
    current_cells[next_service_index()] = json::value::string(arg);
  }
}
