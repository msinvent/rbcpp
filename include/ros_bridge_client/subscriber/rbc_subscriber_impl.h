//
// Created by Julian on 15.10.18.
//

#include <ros_bridge_client/subscriber/rbc_subscriber.h>
#include <ros_bridge_client/msgs/rbc_message.h>

using namespace ros_bridge_client::subscriber;
using namespace ros_bridge_client::msgs;

template<typename T>
RBCSubscriber<T>::RBCSubscriber(std::shared_ptr<ROSBridgeClient> rbc, std::string topic, std::string msg_type,
                                size_t buffer_size,
                                std::function<void(std::shared_ptr<T>)> cb)
  : SubscriberBase(topic, msg_type),
    buffer_size(buffer_size),
    rbc(rbc),
    received_msg(nullptr),
    callback(cb)
{
//  messages.push(std::make_shared<MessageBase>());
  subscribe();
}

template<typename T>
RBCSubscriber<T>::~RBCSubscriber()
{
  unsubscribe();
}

//template<typename T>
//std::shared_ptr<RBCMessage> RBCSubscriber<T>::latest() const
//{
//  return messages.back();
//}
//
//template<typename T>
//size_t RBCSubscriber<T>::queue_size() const
//{
//  return messages.size();
//}

template<typename T>
void RBCSubscriber<T>::addMessage(const web::json::value &json_msg)
{
  received_msg = std::make_shared<T>(json_msg);
//  std::cout << "Received: " << RBCMessage::toString(json_msg) << "\n";
  callback(received_msg);
//  if (messages.size() >= buffer_size)
//  {
//    messages.pop();
//    messages.push(received_msg);
//    return;
//  }
//  messages.push(received_msg);
}

template<typename T>
void RBCSubscriber<T>::subscribe()
{
  rbc->log.log("Subscribing to ", getTopic(), msg());

  rbc->send(msg());
}

template<typename T>
void RBCSubscriber<T>::unsubscribe()
{
  try
  {
    json.erase("type");
  } catch (const std::exception &e)
  {
    std::cerr << "Can't delete key 'type': " << e.what() << std::endl;
  }

  json[U("op")] = web::json::value::string("unsubscribe");

  rbc->log.log("Unsubscribing from ", getTopic(), msg());

  rbc->send(msg());
}
