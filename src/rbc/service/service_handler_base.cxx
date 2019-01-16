//
// Created by julian on 14.01.19.
//

#include <rbc/service/service_handler_base.h>

using namespace rbc::srv;

void ServiceHandlerBase::addResponse(const web::json::value &response)
{
  std::cout << "This should never happen: Base class of Service Listener called\n";
  std::cout << "Got: " << response << "\n";
}

const web::json::value &ServiceHandlerBase::msg() const
{
  return received_message;
}
