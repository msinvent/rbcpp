//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_RBCPUBLISHER_HPP
#define ROSBRIDGECLIENT_RBCPUBLISHER_HPP

#include <string>
#include <cpprest/json.h>
#include <rbc/ros_bridge_client.h>
#include <rbc/publisher/publisher.h>
#include <rbc/service/service_call_message.h>

namespace rbc::publisher
{

template<class T>
class RBCPublisher
{
public:
  RBCPublisher() = delete;

  RBCPublisher(std::shared_ptr<ROSBridgeClient> rbc, std::string topic, std::string msg_type);

  ~RBCPublisher();

  void publish(T &msg) const;

  template <typename S>
  void publish(const srv::ServiceCall<S> &srv_call)
  {
    srv::ServiceCallMessage s(srv_call);
    rbc->send(s.toString());
  }

private:
  void reset();

  void advertise();

  void unadvertise();

  const std::string topic, msg_type;
  std::shared_ptr<ROSBridgeClient> rbc;
  web::json::value json;
};

} // namespace rbc::publisher

#include <rbc/publisher/rbc_publisher_impl.h>

#endif //ROSBRIDGECLIENT_RBCPUBLISHER_HPP
