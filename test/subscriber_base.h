//
// Created by Julian on 17.10.18.
//

#ifndef ROSBRIDGECLIENT_SUBSCRIBER_BASE_H
#define ROSBRIDGECLIENT_SUBSCRIBER_BASE_H

#include <string>

struct SubscriberBase {
  SubscriberBase() = delete;
  virtual ~SubscriberBase() = default;
  SubscriberBase(std::string topic);
  const std::string topic;
};

#endif //ROSBRIDGECLIENT_SUBSCRIBER_BASE_H
