//
// Created by Julian
//

#include <ros_bridge_client/msgs/rbc_message.h>

#ifndef ROSBRIDGECLIENT_RBC_ARRAY_MESSAGE_HPP
#define ROSBRIDGECLIENT_RBC_ARRAY_MESSAGE_HPP

struct ServiceDef
{
public:
  ServiceDef(std::string json_descriptor = "args")
    : json_descriptor(json_descriptor),
      op("service_call")
  {}

  ~ServiceDef() = default;

  const std::string json_descriptor;
  const std::string op;
};

namespace ros_bridge_client
{
namespace msgs
{

class RBCArrayMessage : public RBCMessage
{
public:
  RBCArrayMessage() = delete;

  explicit RBCArrayMessage(std::string array_description);

  explicit RBCArrayMessage(const ServiceDef &service);

  ~RBCArrayMessage() override = default;

protected:
  long next_index() const;

  size_t next_service_index() const;

  const std::string array_descriptor;

private:
  web::json::value createJsonMsg() const override;
};

} // namespace msgs
} // namespace ros_bridge_client


#endif //ROSBRIDGECLIENT_RBC_ARRAY_MESSAGE_HPP