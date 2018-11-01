//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_HPP
#define ROSBRIDGECLIENT_HPP

#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <cpprest/ws_client.h>
#include <ros_bridge_client/logging/logger.h>
#include <ros_bridge_client/msgs/rbc_message.h>
#include <ros_bridge_client/subscriber/rbc_subscriber_base.h>
#include <ros_bridge_client/subscriber/response_to_message.h>

namespace ros_bridge_client
{

namespace publisher
{
template<typename T>
class RBCPublisher;
}
namespace subscriber
{
template<typename T>
class RBCSubscriber;
}

using WSClient = web::websockets::client::websocket_callback_client;

class ROSBridgeClient : public std::enable_shared_from_this<ROSBridgeClient>
{
public:
  ROSBridgeClient() = delete;

  static std::shared_ptr<ROSBridgeClient> init(std::string addr);

  virtual ~ROSBridgeClient();

  bool connectionOk() const;

  void send(const msgs::RBCMessage &msg);

  void send(const msgs::RBCMessage *msg);

  void send(const web::json::value &msg);

  void send(const std::string msg);

  void receive();

  template<typename T>
  std::shared_ptr<subscriber::RBCSubscriber<T>> addSubscriber(std::string topic, size_t buffer_size,
                                                              std::function<void(std::shared_ptr<T>)> cb);

  template<typename T>
  std::shared_ptr<publisher::RBCPublisher<T>> addPublisher(std::string topic);

  logging::Logger log;

private:
  ROSBridgeClient(const std::string addr);

  void connect(const std::string addr);

  bool connected;
  WSClient ws_client;

  std::vector<std::weak_ptr<subscriber::SubscriberBase>> subscribers;
};
} // namespace ros_bridge_client

#include <ros_bridge_client/ros_bridge_client_impl.h>

#endif //ROSBRIDGECLIENT_HPP
