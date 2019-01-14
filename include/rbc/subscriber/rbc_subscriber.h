//
// Created by Julian on 15.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_SUBSCRIBER_H
#define ROSBRIDGECLIENT_RBC_SUBSCRIBER_H

#include <string>
#include <queue>
#include <cpprest/json.h>
#include <memory>
#include <functional>
#include <rbc/ros_bridge_client.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/subscriber/rbc_subscriber_base.h>

namespace rbc::subscriber
{

template<typename T>
class RBCSubscriber : public SubscriberBase
{
public:
  RBCSubscriber() = delete;
  // TODO asser no nullptr function pointer
  RBCSubscriber(std::shared_ptr<ROSBridgeClient> rbc, std::string topic, std::string msg_type, size_t buffer_size,
                std::function<void(std::shared_ptr<T>)> cb);

  ~RBCSubscriber() final;

  void addMessage(const web::json::value &json_msg) final;

private:
  const size_t buffer_size;
  std::shared_ptr<ROSBridgeClient> rbc;
  std::shared_ptr<T> received_msg;
  std::function<void(std::shared_ptr<T>)> callback;
  void subscribe();
  void unsubscribe();
};

} // namespace rbc::subscriber

#include <rbc/subscriber/rbc_subscriber_impl.h>

#endif //ROSBRIDGECLIENT_RBC_SUBSCRIBER_H
