//
// Created by julian on 14.01.19.
//

#ifndef ROSBRIDGECLIENT_SERVICE_BASE_H
#define ROSBRIDGECLIENT_SERVICE_BASE_H

#include <string>
#include <vector>
#include <cpprest/json.h>

namespace rbc::srv
{

struct ServiceHandlerBase
{
  virtual ~ServiceHandlerBase() = default;

  virtual void addResponse(const web::json::value &response);

protected:
  ServiceHandlerBase() = default;


  std::string response_name;

  web::json::value received_message;

  const web::json::value &msg() const;

};

} // namespace rbc::srv

#endif //ROSBRIDGECLIENT_SERVICE_BASE_H
