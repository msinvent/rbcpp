//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_HEADER_MESSAGE_H
#define ROSBRIDGECLIENT_HEADER_MESSAGE_H

#include <rbc/msgs/ros_type_base.h>
#include <memory>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct Header : public ROSTypeBase
{
  Header();

  explicit Header(std::string frame_id);

  explicit Header(const web::json::value &response);

  ~Header() final = default;


  double seq;
  struct Stamp
  {
    inline Stamp() : sec(0), nsec(0) {}
    inline Stamp(double sec, double nsec) : sec(sec), nsec(nsec) {}
    ~Stamp() = default;
    double sec;
    double nsec;
  } stamp;

  std::string frame_id;
};

} // namespace rbc::msgs::std_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::std_msgs::Header &h);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::std_msgs::Header> &h);

#endif //ROSBRIDGECLIENT_HEADER_MESSAGE_H
