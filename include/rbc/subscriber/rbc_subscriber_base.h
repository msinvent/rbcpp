//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_SUBSCRIBER_HPP
#define ROSBRIDGECLIENT_SUBSCRIBER_HPP

#include <string>
#include <sstream>
#include <cpprest/json.h>

namespace rbc::subscriber
{

class SubscriberBase
{
public:
  SubscriberBase() = delete;

  virtual ~SubscriberBase() = default;

  virtual void addMessage(const web::json::value &json_msg);

  const std::string &getTopic() const;

  const std::string &getMsgType() const;

protected:
  SubscriberBase(std::string topic, std::string msg_type);

  web::json::value json;

  const web::json::value &msg() const;
};

} // namespace rbc::subscriber

#endif //ROSBRIDGECLIENT_SUBSCRIBER_HPP
