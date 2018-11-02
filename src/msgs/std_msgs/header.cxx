//
// Created by Julian on 05.10.18.
//

#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/utils/response_converter.h>

using namespace ros_bridge_client::msgs::std_msgs;
using namespace web;

Header::Header()
  : MessageBase("std_msgs/Header"),
    seq(0),
    stamp(0, 0),
    frame_id("world")
{}

Header::Header(std::string frame_id)
  : MessageBase("std_msgs/Header"),
    seq(0),
    stamp(0, 0),
    frame_id(frame_id)
{}

Header::Header(const web::json::value &response)
  : MessageBase("std_msgs/Header"),
    seq(0),
    stamp(0, 0),
    frame_id("world")
{
  std::tie(seq, stamp.sec, stamp.nsec, frame_id) = utils::ResponseConverter::responseToHeader(response, false);
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
