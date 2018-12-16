//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_SERVICE_MESSAGE_HPP
#define ROSBRIDGECLIENT_SERVICE_MESSAGE_HPP

#include <rbc/msgs/rbc_array_message.h>

namespace rbc::msgs::service
{

class ServiceMessage : public RBCArrayMessage
{
public:
  ServiceMessage();

  ServiceMessage(const std::vector<std::string> &args);

  ~ServiceMessage() final = default;

  void setServiceName(const std::string &service_name);

  void setArgs(const std::vector<std::string> &args);
};

} // namespace rbc::msgs::service


#endif //ROSBRIDGECLIENT_SERVICE_MESSAGE_HPP