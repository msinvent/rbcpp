//
// Created by julian on 18.12.18.
//

#ifndef ROSBRIDGECLIENT_TEMPERATURE_H
#define ROSBRIDGECLIENT_TEMPERATURE_H

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>

namespace rbc::msgs::sensor_msgs
{

struct Temperature : public ROSTypeBase
{
  Temperature();

  Temperature(std::string frame_id, double temperature, double variance);

  Temperature(const std_msgs::Header &header, double temperature, double variance);

  Temperature(const web::json::value &response);

  ~Temperature() final = default;

  std_msgs::Header header;
  double temperature;
  double variance;
};

} // namespace rbc::msgs::sensor_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::Temperature &temp);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::Temperature> temp);


#endif //ROSBRIDGECLIENT_TEMPERATURE_H
