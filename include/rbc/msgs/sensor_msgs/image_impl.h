//
// Created by julian on 18.12.18.
//

#include <rbc/msgs/sensor_msgs/image.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::sensor_msgs;

template<std::uint32_t HEIGHT, std::uint32_t WIDTH>
Image<HEIGHT, WIDTH>::Image(std::string frame_id)
    : ROSTypeBase("sensor_msgs/Image"),
      header(frame_id),
      height(HEIGHT),
      width(WIDTH),
      encoding(),
      is_bigendian(),
      step(),
      data()
{}

template<std::uint32_t HEIGHT, std::uint32_t WIDTH>
Image<HEIGHT, WIDTH>::Image(const web::json::value &response)
    : ROSTypeBase("sensor_msgs/Image"),
      header(),
      height(HEIGHT),
      width(WIDTH),
      encoding(),
      is_bigendian(),
      step(),
      data()
{
  const auto &msg = response.at(U("msg"));
  utils::Deserializer::deserialize(header, msg.at("header"), true);
  utils::Deserializer::deserializeSingle(height, msg.at(U("height")));
  utils::Deserializer::deserializeSingle(width, msg.at(U("width")));
  encoding = msg.at(U("encoding")).as_string();
  utils::Deserializer::deserializeSingle(is_bigendian, msg.at(U("is_bigendian")));
  utils::Deserializer::deserializeSingle(step, msg.at(U("step")));
  std::cout << response;
  //utils::Deserializer::toArray<std::uint8_t, HEIGHT*WIDTH>(data, msg.at(U("data")));
}