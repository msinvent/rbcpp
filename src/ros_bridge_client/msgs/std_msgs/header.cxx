//
// Created by Julian on 05.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::std_msgs;
using namespace web;

Header::Header()
  : ROSTypeBase("std_msgs/Header"),
    seq(0),
    stamp(0, 0),
    frame_id("world")
{}

Header::Header(std::string frame_id)
  : ROSTypeBase("std_msgs/Header"),
    seq(0),
    stamp(0, 0),
    frame_id(frame_id)
{}

Header::Header(const web::json::value &response)
  : ROSTypeBase("std_msgs/Header"),
    seq(0),
    stamp(0, 0),
    frame_id("world")
{
  utils::Deserializer::toHeader(*this, response, false);
}

std::ostream &operator<<(std::ostream &os, const Header &h)
{
  os << "\nHeader: ";
  os << "\n\tseq: " << h.seq;
  os << "\n\tstamp: ";
  os << "\n\t\tsecs:  " << h.stamp.sec;
  os << "\n\t\tnsecs: " << h.stamp.nsec;
  os << "\n\tframe_id: " << h.frame_id;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Header> &h)
{
  return os << h.get();
}
