//
// Created by Julian on 20.10.18.
//

#include <rbc/msgs/message.h>


using namespace rbc::msgs;
using namespace web;

template<typename T>
Message<T>::Message(const T &data)
  : json_creator_(),
    data_(data),
    json_msg_(json_creator_.serialize(data, false))
{}

template<typename T>
std::string Message<T>::toString() const
{
  utility::stringstream_t stream;
  json_msg_.serialize(stream);
  return stream.str();
}

template<typename T>
void Message<T>::setTopic(std::string topic)
{
  json_msg_[U("topic")] = web::json::value::string(topic);
}
