//
// Created by Julian on 15.10.18.
//

#include <rbc/subscriber/rbc_subscriber.h>

using namespace rbc::subscriber;
using namespace rbc::msgs;

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
  assert(cb != nullptr && "Callback pointer can't be nullptr!");

  subscribe();
}

template<typename T>
RBCSubscriber<T>::~RBCSubscriber()
{
  unsubscribe();
}

template<typename T>
void RBCSubscriber<T>::addMessage(const web::json::value &json_msg)
{
  received_msg = std::make_shared<T>(json_msg);
  callback(received_msg);
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
