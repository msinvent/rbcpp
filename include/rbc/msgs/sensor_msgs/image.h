//
// Created by julian on 18.12.18.
//

#ifndef ROSBRIDGECLIENT_IMAGE_H
#define ROSBRIDGECLIENT_IMAGE_H

#include <cstdint>
#include <array>
#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>

namespace rbc::msgs::sensor_msgs
{

template <std::uint32_t HEIGHT, std::uint32_t WIDTH>
struct Image : public ROSTypeBase
{
  explicit Image(std::string frame_id = "world");

  explicit Image(const web::json::value &response);

  std_msgs::Header header;
  std::uint32_t height;
  std::uint32_t width;
  std::string encoding;
  std::uint8_t is_bigendian;
  std::uint32_t step;
  std::array<uint8_t, HEIGHT*WIDTH> data;
};

} // namespace rbc::msgs::sensor_msgs

#include <rbc/msgs/sensor_msgs/image_impl.h>

#endif //ROSBRIDGECLIENT_IMAGE_H
