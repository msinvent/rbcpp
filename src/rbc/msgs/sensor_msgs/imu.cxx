//
// Created by julian on 16.12.18.
//

#include <rbc/msgs/sensor_msgs/imu.h>

using namespace rbc::msgs::sensor_msgs;

Imu::Imu()
    : ROSTypeBase("sensor_msgs/Imu"),
      orientation(),
      orientation_covariance(),
      angular_velocity(),
      angular_velocity_covariance(),
      linear_acceleration(),
      linear_acceleration_covariance()
{}

Imu::Imu(const geometry_msgs::Quaternion &orientation, const geometry_msgs::Vector3 &angular_velocity,
         const geometry_msgs::Vector3 &linear_velocity)
    : ROSTypeBase("sensor_msgs/Imu"),
      orientation(orientation),
      orientation_covariance(),
      angular_velocity(angular_velocity),
      angular_velocity_covariance(),
      linear_acceleration(linear_velocity),
      linear_acceleration_covariance()
{}

Imu::Imu(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/Imu"),
      orientation(),
      orientation_covariance(),
      angular_velocity(),
      angular_velocity_covariance(),
      linear_acceleration(),
      linear_acceleration_covariance()
{}
