//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_ACCEL_SUBSCRIBER_H
#define ROSBRIDGECLIENT_RBC_ACCEL_SUBSCRIBER_H

#include <rbc/subscriber/private/rbc_subscriber.h>
#include <rbc/msgs/geometry_msgs/accel_message.h>

namespace rbc::subscriber
{

class RBCAccelSubscriber : public RBCSubscriber<geometry_msgs::AccelMessage>
{
public:
  RBCAccelSubscriber() = delete;
  RBCAccelSubscriber(ROSBridgeClient &wsc, std::string topic, size_t buffer_size = 100);
  ~RBCAccelSubscriber() final = default;

  void addMessage(const web::json::value &json_msg) final;
};
} // namespace rbc::subscriber

#endif //ROSBRIDGECLIENT_RBC_ACCEL_SUBSCRIBER_H