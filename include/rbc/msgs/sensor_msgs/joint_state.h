//
// Created by julian on 19.12.18.
//

#ifndef ROSBRIDGECLIENT_JOINT_STATE_H
#define ROSBRIDGECLIENT_JOINT_STATE_H

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>

namespace rbc::msgs::sensor_msgs
{

struct JointState : public ROSTypeBase
{
  JointState();

  JointState(const std::vector<std::string> &name, std::string frame_id, const std::vector<double> &position,
             const std::vector<double> &velocity, const std::vector<double> &effort);

  JointState(const std::vector<std::string> &name, const std_msgs::Header &header, const std::vector<double> &position,
             const std::vector<double> &velocity, const std::vector<double> &effort);

  explicit JointState(const web::json::value &response);

  ~JointState() final = default;

  std_msgs::Header header;
  std::vector<std::string> name;
  std::vector<double> position;
  std::vector<double> velocity;
  std::vector<double> effort;
};

} // namespace rbc::msgs::sensor_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::JointState &j);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::JointState> &j);

#endif //ROSBRIDGECLIENT_JOINT_STATE_H
