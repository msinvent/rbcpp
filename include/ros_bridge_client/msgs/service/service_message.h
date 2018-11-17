//
// Created by Julian
//

#ifndef ROSBRIDGECLIENT_SERVICE_MESSAGE_HPP
#define ROSBRIDGECLIENT_SERVICE_MESSAGE_HPP

#include <ros_bridge_client/msgs/rbc_array_message.h>

namespace ros_bridge_client::msgs::service
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

} // namespace ros_bridge_client::msgs::service


#endif //ROSBRIDGECLIENT_SERVICE_MESSAGE_HPP