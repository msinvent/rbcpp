//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_RBCPUBLISHER_HPP
#define ROSBRIDGECLIENT_RBCPUBLISHER_HPP

#include <string>
#include <cpprest/json.h>
#include <ros_bridge_client/ros_bridge_client.h>
#include <ros_bridge_client/publisher/publisher.h>

namespace ros_bridge_client::publisher
{

template<class T>
class RBCPublisher
{
public:
  RBCPublisher() = delete;

  RBCPublisher(std::shared_ptr<ROSBridgeClient> rbc, std::string topic, std::string msg_type);

  ~RBCPublisher();

  void publish(T &msg) const;

private:
  void reset();

  void advertise();

  void unadvertise();

  const std::string topic, msg_type;
  std::shared_ptr<ROSBridgeClient> rbc;
  web::json::value json;
};

} // namespace ros_bridge_client::publisher

#include <ros_bridge_client/publisher/rbc_publisher_impl.h>

#endif //ROSBRIDGECLIENT_RBCPUBLISHER_HPP
