//
// Created by julian on 16.12.18.
//

#ifndef ROSBRIDGECLIENT_IMU_H
#define ROSBRIDGECLIENT_IMU_H

#include <array>
#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/vector3.h>
#include <rbc/msgs/geometry_msgs/quaternion.h>

namespace rbc::msgs::sensor_msgs
{

struct Imu : public ROSTypeBase
{
  Imu();

  Imu(const geometry_msgs::Quaternion &orientation, const geometry_msgs::Vector3 &angular_velocity,
      const geometry_msgs::Vector3 &linear_velocity);

  Imu(const web::json::value &response);

  ~Imu() final = default;

  geometry_msgs::Quaternion orientation;
  std::array<float, 9> orientation_covariance;

  geometry_msgs::Vector3 angular_velocity;
  std::array<float, 9> angular_velocity_covariance;

  geometry_msgs::Vector3 linear_acceleration;
  std::array<float, 9> linear_acceleration_covariance;
};

} // namespace rbc::msgs::sensor_msgs

#endif //ROSBRIDGECLIENT_IMU_H
