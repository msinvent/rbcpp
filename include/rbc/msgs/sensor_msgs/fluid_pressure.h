//
// Created by julian on 07.01.19.
//

#ifndef ROSBRIDGECLIENT_FLUID_PRESSURE_H
#define ROSBRIDGECLIENT_FLUID_PRESSURE_H

#include <string>
#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>

namespace rbc::msgs::sensor_msgs
{

struct FluidPressure : public ROSTypeBase
{
  FluidPressure();

  FluidPressure(std::string frame_id, double pressure, double variance);

  explicit FluidPressure(const web::json::value &response);

  ~FluidPressure() final = default;

  std_msgs::Header header;
  double fluid_pressure;
  double variance;
};

} // namespace rbc::msgs::sensor_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::sensor_msgs::FluidPressure &fp);

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::sensor_msgs::FluidPressure> fp);

#endif //ROSBRIDGECLIENT_FLUID_PRESSURE_H
