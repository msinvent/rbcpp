//
// Created by Julian on 22.10.18.
//

#ifndef ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
#define ROSBRIDGECLIENT_RESPONSE_CONVERTER_H

#include <cpprest/json.h>
#include <tuple>
#include <vector>
#include <thread>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/std_msgs/std_msg.h>
#include <rbc/msgs/std_msgs/color_rgba.h>
#include <rbc/msgs/geometry_msgs/point.h>
#include <rbc/msgs/geometry_msgs/pose.h>
#include <rbc/msgs/geometry_msgs/pose2d.h>
#include <rbc/msgs/xyzmessage.h>
#include <rbc/msgs/geometry_msgs/vector3.h>
#include <rbc/msgs/geometry_msgs/point32.h>
#include <rbc/msgs/geometry_msgs/inertia.h>
#include <rbc/msgs/geometry_msgs/polygon.h>
#include <rbc/msgs/geometry_msgs/quaternion.h>
#include <rbc/msgs/geometry_msgs/pose_array.h>

namespace rbc::utils
{

struct Deserializer
{
  template<typename T>
  static void deserialize(msgs::XYZMessage<T> &xyz, const web::json::value &response, bool is_sub_json = false);

  template<typename T>
  static void deserialize(msgs::std_msgs::StdMsg<T> &std, const web::json::value &response, bool is_sub_json = false);

  template<typename T>
  static void deserialize(std::vector<T> &vec, const web::json::value &response);

  template<typename T, unsigned int N>
  static void toArray(std::array<T, N> &array, const web::json::value &response);

  static std::string toString(const web::json::value &response);

  static void deserialize(std::string &str, const web::json::value &response, bool is_sub_json = false);

  static void deserialize(msgs::geometry_msgs::Polygon &polygon, const web::json::value &response, bool is_sub_json = false);

  static void deserialize(msgs::std_msgs::ColorRGBA &color, const web::json::value &response, bool is_sub_json = false);

  static void deserialize(msgs::geometry_msgs::Pose2D &pose, const web::json::value &response, bool is_sub_json = false);

  static void
  deserialize(msgs::geometry_msgs::Inertia &inertia, const web::json::value &response, bool is_sub_json = false);

  static void
  deserialize(msgs::geometry_msgs::Quaternion &quaternion, const web::json::value &response, bool is_sub_json = false);

  static void deserialize(msgs::std_msgs::Header &header, const web::json::value &response, bool is_sub_json = false);

  template <typename T>
  static void deserialize(std::vector<T> &vector, const web::json::array &value);

  template <typename T>
  static void deserialize(std::vector<T> &vec, const web::json::value &response, std::string key);

  template <typename T>
  static void deserialize_singles(std::vector<T> &vec, const web::json::value &response, std::string key);

  static void deserialize(msgs::geometry_msgs::Pose &pose, const web::json::value &response, bool is_sub_json);
};

template<typename T>
void Deserializer::deserialize(msgs::XYZMessage<T> &xyz, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  xyz.x = static_cast<T>(msg.at(U("x")).as_double());
  xyz.y = static_cast<T>(msg.at(U("y")).as_double());
  xyz.z = static_cast<T>(msg.at(U("z")).as_double());
}

template<typename T>
void Deserializer::deserialize(msgs::std_msgs::StdMsg<T> &std, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  std.data = static_cast<T>(msg.at("data").as_double());
}

template<typename T>
void Deserializer::deserialize(std::vector<T> &vec, const web::json::value &response)
{
  const auto &msg = response.at(U("arr")).as_array();
  std::vector<web::json::value> json_vec(msg.cbegin(), msg.cend());
  for (const auto &val: json_vec)
  {
    vec.push_back(static_cast<T>(val.as_double()));
  }
}

template<typename T, unsigned int N>
void Deserializer::toArray(std::array<T, N> &arr, const web::json::value &response)
{
  const auto &json_arr = response.as_array();
  auto arr_size = std::distance(json_arr.cbegin(), json_arr.cend());

  if (arr_size > N)
  {
    std::fill(std::begin(arr), std::end(arr), NAN);
    std::cerr << "Json array too big\n";
    return;
  }

  auto it = json_arr.cbegin();

  std::generate(std::begin(arr), std::end(arr), [&]
  {
    return static_cast<T>((*it++).as_double());
  });
}

template <typename T>
void Deserializer::deserialize(std::vector<T> &vec, const web::json::value &response, std::string key)
{
  const auto &json_arr = response.at(U(key)).as_array();
  auto arr_size = std::distance(json_arr.cbegin(), json_arr.cend());
  vec.reserve(arr_size);

  deserialize<T>(vec, json_arr);
}

template<typename T>
void Deserializer::deserialize(std::vector<T> &vector, const web::json::array &json_arr)
{
  auto it = json_arr.cbegin();
  while (it != json_arr.cend())
  {
    T t;
    Deserializer::deserialize(t, *it++, true);
    vector.push_back(t);
  }
}

template <typename T>
void Deserializer::deserialize_singles(std::vector<T> &vec, const web::json::value &response, std::string key)
{
  const auto &json_arr = response.at(U(key)).as_array();
  auto arr_size = std::distance(json_arr.cbegin(), json_arr.cend());
  vec.reserve(arr_size);

  auto it = json_arr.cbegin();
  while (it != json_arr.cend())
  {
    vec.push_back(static_cast<T>(it->as_double()));
    it++;
  }
}

} // namespace rbc::util


#endif //ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
