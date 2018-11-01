//
// Created by Julian on 17.10.18.
//

#ifndef ROSBRIDGECLIENT_PUBLISHER_H
#define ROSBRIDGECLIENT_PUBLISHER_H

#include <string>
#include "manager.h"
#include "publisher_base.h"

template <typename T>
struct Publisher : public PublisherBase
{
  Publisher() = delete;
  explicit Publisher(std::shared_ptr<ROSBridgeClient> manager, std::string topic) : PublisherBase(topic), manager(manager) {}
  ~Publisher() = default;
  inline void publish(T data)
  {
    manager->send(topic, data);
  }
  std::shared_ptr<ROSBridgeClient> manager;
};

using PublisherBasePtr = std::shared_ptr<PublisherBase>;

#endif //ROSBRIDGECLIENT_PUBLISHER_H
