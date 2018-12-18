//
// Created by gjulian on 17.12.18.
//

#include <rbc/msgs/sensor_msgs/joy.h>
#include <rbc/utils/deserializer.h>

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
{
  const auto &msg = response.at(U("msg"));
  const auto &header_msg = msg.at(U("header"));

  utils::Deserializer::deserialize(header, header_msg, true);

  utils::Deserializer::deserialize_singles(axes, msg, "axes");

  utils::Deserializer::deserialize_singles(buttons, msg, "buttons");
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::Joy &joy)
{
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::Joy> &joy)
{
  return os << *joy.get();
}
