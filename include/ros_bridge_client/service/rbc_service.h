//
// Created by Julian on 15.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_SERVICE_H
#define ROSBRIDGECLIENT_RBC_SERVICE_H

#include <ros_bridge_client/ros_bridge_client.h>
#include <ros_bridge_client/msgs/service/service_message.h>

namespace ros_bridge_client
{
namespace service
{

class RBCService
{
public:
  RBCService() = delete;

  RBCService(ROSBridgeClient &client, std::string service_name);

  ~RBCService();

  void call(msgs::service::ServiceMessage &msg) const;

private:
  ROSBridgeClient &ws_client;
  const std::string service_name;
};

} // namespace service
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_RBC_SERVICE_H
