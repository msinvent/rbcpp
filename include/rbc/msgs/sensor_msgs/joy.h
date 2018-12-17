//
// Created by gjulian on 17.12.18.
//

#ifndef ROSBRIDGECLIENT_JOY_H
#define ROSBRIDGECLIENT_JOY_H

#include <vector>
#include <cpprest/json.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::sensor_msgs
{

struct Joy : public ROSTypeBase
{
  explicit Joy(std::string frame_id = "world");

  Joy(const web::json::value &response);

  ~Joy() final = default;

  std_msgs::Header header;
  std::vector<float> axes;
  std::vector<int32_t> buttons;
};

} // namespace rbc::msgs::sensor_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::Joy &joy);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::Joy> &joy);

#endif //ROSBRIDGECLIENT_JOY_H
