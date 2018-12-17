//
// Created by gjulian on 17.12.18.
//

#include <rbc/msgs/sensor_msgs/joy.h>

using namespace rbc::msgs::sensor_msgs;

Joy::Joy(std::string frame_id)
    : ROSTypeBase("sensor_msgs/Joy"),
      header(frame_id),
      axes(),
      buttons()
{}

Joy::Joy(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/Joy"),
      header(),
      axes(),
      buttons()
{}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::Joy &joy)
{
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::Joy> &joy)
{
  return os << *joy.get();
}
