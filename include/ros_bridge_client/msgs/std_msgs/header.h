//
// Created by Julian on 05.10.18.
//

#ifndef ROSBRIDGECLIENT_HEADER_MESSAGE_H
#define ROSBRIDGECLIENT_HEADER_MESSAGE_H

#include <ros_bridge_client/msgs/message_base.h>
#include <memory>
#include <cpprest/json.h>

namespace ros_bridge_client
{
namespace msgs
{
namespace std_msgs
{

struct Header : public MessageBase
{
  Header();

  explicit Header(std::string frame_id);

  explicit Header(const web::json::value &response);

  ~Header() final = default;


  double seq;
  struct Stamp
  {
    double sec;
    double nsec;
  } stamp;

  std::string frame_id;
};

} // namespace std_msgs
} // namespace msgs
} // namespace ros_bridge_client

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::std_msgs::Header &h);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::std_msgs::Header> &h);

#endif //ROSBRIDGECLIENT_HEADER_MESSAGE_H
