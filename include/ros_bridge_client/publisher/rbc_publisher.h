//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_RBCPUBLISHER_HPP
#define ROSBRIDGECLIENT_RBCPUBLISHER_HPP

#include <string>
#include <cpprest/json.h>
#include <ros_bridge_client/ros_bridge_client.h>
#include <ros_bridge_client/publisher/publisher.h>
#include <ros_bridge_client/msgs/rbc_message.h>

namespace ros_bridge_client::publisher
{

template<class T>
class RBCPublisher : public msgs::RBCMessage
{
public:
  RBCPublisher() = delete;

  RBCPublisher(std::shared_ptr<ROSBridgeClient> rbc, std::string topic, std::string msg_type);

  ~RBCPublisher() final;

  void publish(T &msg) const;

private:
  void advertise();

  void unadvertise();

  const std::string mode;
  const std::string topic;

  std::shared_ptr<ROSBridgeClient> rbc;
};

} // namespace ros_bridge_client::publisher

#include <ros_bridge_client/publisher/rbc_publisher_impl.h>

#endif //ROSBRIDGECLIENT_RBCPUBLISHER_HPP
