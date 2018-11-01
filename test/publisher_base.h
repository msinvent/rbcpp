//
// Created by Julian on 17.10.18.
//

#ifndef ROSBRIDGECLIENT_PUBLISHER_BASE_H
#define ROSBRIDGECLIENT_PUBLISHER_BASE_H

#include <string>

struct PublisherBase
{
  PublisherBase() = delete;
  explicit PublisherBase(std::string topic);
  virtual ~PublisherBase() = default;
  std::string topic;
};


#endif //ROSBRIDGECLIENT_PUBLISHER_BASE_H
