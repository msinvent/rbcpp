//
// Created by julian on 18.12.18.
//

#include <rbc/msgs/sensor_msgs/image.h>

using namespace rbc::msgs::sensor_msgs;

template<std::uint32_t HEIGHT, std::uint32_t WIDTH>
Image<HEIGHT, WIDTH>::Image()
    : ROSTypeBase("sensor_msgs/Image"),
      height(HEIGHT),
      width(WIDTH),
      encoding(),
      is_bigendian(),
      step()
{}

template<std::uint32_t HEIGHT, std::uint32_t WIDTH>
Image<HEIGHT, WIDTH>::Image(std::string frame_id)
    : ROSTypeBase("sensor_msgs/Image"),
      height(HEIGHT),
      width(WIDTH),
      encoding(),
      is_bigendian(),
      step()
{}

template<std::uint32_t HEIGHT, std::uint32_t WIDTH>
Image<HEIGHT, WIDTH>::Image(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/Image"),
      height(HEIGHT),
      width(WIDTH),
      encoding(),
      is_bigendian(),
      step()
{}