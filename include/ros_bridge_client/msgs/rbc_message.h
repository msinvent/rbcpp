//
// Created by Julian on 14.09.18.
//

#ifndef ROSBRIDGECLIENT_RBC_MESSAGE_HPP
#define ROSBRIDGECLIENT_RBC_MESSAGE_HPP

#include <string>
#include <sstream>
#include <cpprest/json.h>

namespace ros_bridge_client
{
namespace msgs
{

class RBCMessage
{
public:
  RBCMessage();

  virtual ~RBCMessage() = default;

  const web::json::value &msg() const;

  void setTopic(std::string topic);

  void setMode(std::string op);

  const web::json::value &getJsonAt(std::string key = "msg") const;

  std::string toString() const;

  static std::string toString(const web::json::value &json);

protected:
  RBCMessage(std::string op);

  virtual web::json::value createJsonMsg() const;

  web::json::value json;
  web::json::value fallback_json;
  std::string topic;
};

} // namespace msgs
} // namespace ros_bridge_client

#endif //ROSBRIDGECLIENT_RBC_MESSAGE_HPP
