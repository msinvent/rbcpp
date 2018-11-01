//
// Created by Julian
//
#include <ros_bridge_client/msgs/rbc_array_message.h>


using namespace ros_bridge_client::msgs;
using namespace web;

RBCArrayMessage::RBCArrayMessage(std::string array_description)
  : array_descriptor(array_description)
{
  json[U("msg")] = createJsonMsg();
}

RBCArrayMessage::RBCArrayMessage(const ServiceDef &service)
  : RBCMessage(service.op)
{
  json[U(service.json_descriptor)] = json::value::array();
}

json::value RBCArrayMessage::createJsonMsg() const
{
  json::value json_array;
  json_array[U(array_descriptor)] = json::value::array();
  return json_array;
}

long RBCArrayMessage::next_index() const
{
  const auto &array = json.at(U("msg")).at(U(array_descriptor)).as_array();
  return std::distance(array.begin(), array.end());
}

size_t RBCArrayMessage::next_service_index() const
{
  const auto &array = json.at("args").as_array();
  return std::distance(array.begin(), array.end());
}
