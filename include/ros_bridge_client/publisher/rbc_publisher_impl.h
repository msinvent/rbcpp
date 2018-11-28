//
// Created by Julian on 16.10.18.
//

#include <ros_bridge_client/publisher/rbc_publisher.h>
#include <ros_bridge_client/msgs/message.h>

using namespace ros_bridge_client::publisher;

template<typename T>
RBCPublisher<T>::RBCPublisher(std::shared_ptr<ROSBridgeClient> rbc, std::string topic, std::string msg_type)
  : topic(topic),
    msg_type(msg_type),
    rbc(rbc),
    json()
{
  json[U("op")] = web::json::value("publish");
  json[U("topic")] = web::json::value::string(topic);
  json[U("type")] = web::json::value::string(msg_type);
  advertise();
}

template<typename T>
RBCPublisher<T>::~RBCPublisher()
{
  unadvertise();
}

template<typename T>
void RBCPublisher<T>::advertise()
{
  json[U("op")] = web::json::value::string("advertise");

  rbc->log.log("Advertising topic ", topic, json);

  rbc->send(json);

  reset();
}

template<typename T>
void RBCPublisher<T>::unadvertise()
{
  try
  {
    json.erase("type");
  } catch (const std::exception &e)
  {
    std::cerr << "Can't delete key 'type': " << e.what() << std::endl;
  }

  json[U("op")] = web::json::value::string("unadvertise");

  rbc->log.log("Unadvertising topic ", topic, json);

  rbc->send(json);

  reset();
}

template<typename T>
void RBCPublisher<T>::publish(T &m) const
{
  Message<T> msg(m);
  msg.setTopic(topic);
  rbc->send(msg.toString());
}

template<typename T>
void RBCPublisher<T>::reset()
{
  json[U("op")] = web::json::value::string("publish");
  json[U("type")] = web::json::value::string(msg_type);
}
