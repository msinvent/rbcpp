//
// Created by Julian on 17.10.18.
//

#ifndef ROSBRIDGECLIENT_SUBSCRIBER_H
#define ROSBRIDGECLIENT_SUBSCRIBER_H

#include <string>
#include <functional>
#include <memory>
#include "subscriber_base.h"

template <typename T>
struct Subscriber : public SubscriberBase
{
  Subscriber() = delete;
  explicit Subscriber(std::string topic, std::function<void(T)> cb);
  ~Subscriber() override = default;
  std::function<void(T)> cb;
};

template <typename T>
Subscriber<T>::Subscriber(std::string topic, std::function<void(T)> cb)
  : SubscriberBase(topic), cb(cb)
{}

#endif //ROSBRIDGECLIENT_SUBSCRIBER_H
