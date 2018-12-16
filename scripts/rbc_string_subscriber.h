//
// Created by Julian on 14.10.18.
//

#ifndef ROSBRIDGECLIENT_RBC_STRING_SUBSCRIBER_H
#define ROSBRIDGECLIENT_RBC_STRING_SUBSCRIBER_H

#include <rbc/subscriber/private/rbc_subscriber.h>
#include <rbc/msgs/std_msgs/string_message.h>

namespace rbc::subscriber
{

class RBCStringSubscriber : public RBCSubscriber<std_msgs::StringMessage>
{
public:
  RBCStringSubscriber() = delete;
  RBCStringSubscriber(ROSBridgeClient &wsc, std::string topic, size_t buffer_size = 100);
  ~RBCStringSubscriber() final = default;

  void addMessage(const web::json::value &json_msg) final;
};
} // namespace rbc::subscriber

#endif //ROSBRIDGECLIENT_RBC_STRING_SUBSCRIBER_H