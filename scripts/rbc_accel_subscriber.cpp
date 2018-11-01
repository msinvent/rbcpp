//
// Created by Julian on 14.10.18.
//

#include <ros_bridge_client/subscriber/rbc_accel_subscriber.h>
#include <ros_bridge_client/subscriber/response_to_message.h>

using namespace ros_bridge_client::subscriber;

RBCAccelSubscriber::RBCAccelSubscriber(ROSBridgeClient &wsc, std::string topic, size_t buffer_size)
  : RBCSubscriber<geometry_msgs::AccelMessage>(wsc, topic, "geometry_msgs/Accel", buffer_size)
{}

void RBCAccelSubscriber::addMessage(const web::json::value &json_msg)
{
  const auto& msg = conversions::responseToAccelMessage(json_msg);

  if (messages.size() >= buffer_size)
  {
    messages.pop();
    messages.push(msg);
    return;
  }

  messages.push(msg);
  std::cout << getTopic() << " subscriber received: " << msg.toString() << "\n";
}