//
// Created by Julian on 14.09.18.
//

#include <rbc/subscriber/rbc_subscriber_base.h>
#include <cpprest/ws_client.h>

using namespace rbc::subscriber;
using namespace web;

SubscriberBase::SubscriberBase(std::string topic, std::string msg_type)
{
  // these are just default values. They are finally set in publisher/subscriber in publish/subcribe methods
  json[U("op")] = json::value::string("subscribe");
  json[U("topic")] = json::value::string(topic);
  json[U("type")] = web::json::value::string(msg_type);
}

const std::string &SubscriberBase::getTopic() const
{
  return json.at(U("topic")).as_string();
}

const std::string &SubscriberBase::getMsgType() const
{
  return json.at(U("type")).as_string();
}

const json::value &SubscriberBase::msg() const
{
  return json;
}

void SubscriberBase::addMessage(const web::json::value &json_msg)
{
  std::cerr << "This should never happen. Received something in subscriber base class. Size: " << json_msg.size()
            << "\n";
}