//
// Created by julian on 19.12.18.
//

#include <rbc/msgs/sensor_msgs/joint_state.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::sensor_msgs;

JointState::JointState()
    : ROSTypeBase("sensor_msgs/JointState"),
      header(),
      name(),
      position(),
      velocity(),
      effort()
{}

JointState::JointState(const std::vector<std::string> &name, std::string frame_id, const std::vector<double> &position,
                       const std::vector<double> &velocity, const std::vector<double> &effort)
    : ROSTypeBase("sensor_msgs/JointState"),
      header(frame_id),
      name(name),
      position(position),
      velocity(velocity),
      effort(effort)
{}

JointState::JointState(const std::vector<std::string> &name, const rbc::msgs::std_msgs::Header &header,
                       const std::vector<double> &position,
                       const std::vector<double> &velocity, const std::vector<double> &effort)
    : ROSTypeBase("sensor_msgs/JointState"),
      header(header),
      name(name),
      position(position),
      velocity(velocity),
      effort(effort)
{}

JointState::JointState(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/JointState"),
      header(),
      position(),
      velocity(),
      effort()
{
  const auto &msg = response.at(U("msg"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);

  utils::Deserializer::deserializeStrings(name, msg.at("name"));

  utils::Deserializer::deserialize_singles<double>(position, msg, "position");

  utils::Deserializer::deserialize_singles<double>(velocity, msg, "velocity");

  utils::Deserializer::deserialize_singles<double>(effort, msg, "effort");
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::JointState &j)
{
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::JointState> &j)
{
  return os << *j.get();
}
