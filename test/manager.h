//
// Created by Julian on 17.10.18.
//

#ifndef ROSBRIDGECLIENT_MANAGER_H
#define ROSBRIDGECLIENT_MANAGER_H

#include <memory>
#include <functional>
#include <cpprest/ws_client.h>
#include "subscriber.h"
#include "subscriber_base.h"
#include "publisher_base.h"

using WSClient = web::websockets::client::websocket_callback_client;

template <typename T>
struct Publisher;

struct ROSBridgeClient : public std::enable_shared_from_this<ROSBridgeClient>
{
public:
  static inline std::shared_ptr<ROSBridgeClient> init(std::string addr)
  {
    // have to jump trough loops because of https://stackoverflow.com/a/8147213
    // example https://stackoverflow.com/a/25069711
    struct make_share_enabler : public ROSBridgeClient
    {
      make_share_enabler(std::string addr) : ROSBridgeClient(addr) {}
      ~make_share_enabler() override = default;
    };
    static auto manager = std::make_shared<make_share_enabler>(addr);
    return manager;
  }

  virtual ~ROSBridgeClient() = default;

  void connect(std::string addr);

  template <typename T>
  std::shared_ptr<Subscriber<T>> inline addSubscriber(std::string topic, std::function<void(T)> cb);

  template <typename T>
  std::shared_ptr<Publisher<T>> inline addPublisher(std::string topic);

  template <typename T>
  inline void send(std::string topic, T data);
private:
  ROSBridgeClient() = delete;
  ROSBridgeClient(std::string addr);
  std::vector<std::shared_ptr<SubscriberBase>> subscribers;
  std::vector<std::shared_ptr<PublisherBase>> publishers;
  WSClient ws_client;
};

#include "publisher.h"

ROSBridgeClient::ROSBridgeClient(std::string addr)
{
  connect(addr);
}

void ROSBridgeClient::connect(std::string addr)
{
  try
  {
    ws_client.connect(U(addr)).then([&]() {
      std::cout << "Connected to " << addr << std::endl;
    }).wait();
  } catch (const std::exception &e)
  {
    std::cerr << "Can't connect: " << e.what() << std::endl;
  }
}

template <typename T>
std::shared_ptr<Subscriber<T>> ROSBridgeClient::addSubscriber(std::string topic, std::function<void(T)> cb)
{
  auto sub = std::make_shared<Subscriber<T>>(topic, cb);
  subscribers.push_back(sub);
  return sub;
}

template <typename T>
std::shared_ptr<Publisher<T>> ROSBridgeClient::addPublisher(std::string topic)
{
  std::shared_ptr<Publisher<T>> d = std::make_shared<Publisher<T>>(shared_from_this(), topic);
  publishers.push_back(d);
  return d;
}

// std::function<void(const std::string &topic)> == void(*)(const std::string &topic)
template <typename T>
inline void ROSBridgeClient::send(std::string topic, T data)
{
  for (const auto& d: subscribers)
  {
    if (d->topic == topic)
    {
      auto sub = std::dynamic_pointer_cast<Subscriber<T>>(d);
      sub.get()->cb();
    }
  }
}

#endif //ROSBRIDGECLIENT_MANAGER_H
