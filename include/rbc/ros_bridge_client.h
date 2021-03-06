//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_HPP
#define ROSBRIDGECLIENT_HPP

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <cpprest/ws_client.h>
#include <rbc/logging/logger.h>
#include <rbc/subscriber/rbc_subscriber_base.h>

#include <rbc/service/service_handler_base.h>
#include <rbc/service/service_call.h>

namespace rbc
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

namespace srv
{
template <typename T>
struct ServiceHandler;
}

using WSClient = web::websockets::client::websocket_callback_client;

class ROSBridgeClient : public std::enable_shared_from_this<ROSBridgeClient>
{
public:
  ROSBridgeClient() = delete;

  static std::shared_ptr<ROSBridgeClient> init(std::string addr);

  virtual ~ROSBridgeClient();

  void send(const web::json::value &msg);

  void send(const std::string msg);

  void receive();

  template<typename T>
  std::shared_ptr<subscriber::RBCSubscriber<T>> addSubscriber(std::string topic, size_t buffer_size,
                                                              std::function<void(std::shared_ptr<T>)> cb);

  template<typename T>
  std::shared_ptr<publisher::RBCPublisher<T>> addPublisher(std::string topic);

  template <typename T>
  std::shared_ptr<srv::ServiceHandler<T>> addServiceHandler(std::string name, std::string response_name,
                                                            std::function<void(std::shared_ptr<T>)> cb);

  logging::Logger log;

private:
  ROSBridgeClient(const std::string addr);

  void connect(const std::string addr);

  void callServiceResponseHandler(const web::json::value &response);

  void callSubscriberHandler(const web::json::value &response);

  void callHandler(const web::json::value &response);

  WSClient ws_client;

  std::unordered_map<std::string, std::weak_ptr<subscriber::SubscriberBase>> subscribers;
  std::unordered_map<std::string, std::weak_ptr<srv::ServiceHandlerBase>> services;
};
} // namespace rbc

#include <rbc/ros_bridge_client_impl.h>

#endif //ROSBRIDGECLIENT_HPP
