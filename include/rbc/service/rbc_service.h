//
// Created by Julian on 15.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_SERVICE_H
#define ROSBRIDGECLIENT_RBC_SERVICE_H

#include <rbc/ros_bridge_client.h>
#include <rbc/msgs/service/service_message.h>

namespace rbc::service
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

} // namespace rbc::service

#endif //ROSBRIDGECLIENT_RBC_SERVICE_H
