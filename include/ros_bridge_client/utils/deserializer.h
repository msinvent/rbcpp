//
// Created by Julian on 22.10.18.
//

#ifndef ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
#define ROSBRIDGECLIENT_RESPONSE_CONVERTER_H

#include <cpprest/json.h>
#include <tuple>
#include <vector>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/std_msgs/color_rgba.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>

namespace ros_bridge_client::utils
{

using PointTuple = std::tuple<double, double, double>;
using PolygonStampedTuple = std::tuple<std::vector<msgs::geometry_msgs::Point32>, msgs::std_msgs::Header>;
using ColorTuple = std::tuple<float, float, float, float>;
using InertiaTuple = std::tuple<double, double, double, double, double, double, double>;
using PoseTuple = std::tuple<msgs::geometry_msgs::Point, msgs::geometry_msgs::Quaternion>;
using Point32Tuple = std::tuple<float, float, float>;
using QuaternionTuple = std::tuple<double, double, double, double>;
using HeaderTuple = std::tuple<double, double, double, std::string>;

struct Deserializer
{
  static const std::string convToString(const web::json::value &json);

  static const std::string &toString(const web::json::value &response, bool is_sub_json = false);

  template <typename T>
  static T toStdMsg(const web::json::value &response, bool is_sub_json = false);

  template <typename T>
  static void toArray(std::vector<T> &vec, const web::json::value &response);

  template <typename T, unsigned int N>
  static std::array<T, N>& toArray(const web::json::value &response);

  static std::vector<msgs::geometry_msgs::Point32> &toPolygon(const web::json::value &response);

  static void toPolygonStamped(std::vector<msgs::geometry_msgs::Point32> &points, msgs::std_msgs::Header &header,
                                 const web::json::value &response);

  static void toColor(msgs::std_msgs::ColorRGBA &color, const web::json::value &response, bool is_sub_json = false);

  static PointTuple toPoint(const web::json::value &response, bool is_sub_json = false);
  
  static PointTuple toPose2D(const web::json::value &response, bool is_sub_json = false);

  static InertiaTuple toInertia(const web::json::value &response, bool is_sub_json = false);

  static Point32Tuple toPoint32(const web::json::value &response, bool is_sub_json = false);

  static void
  toQuaternion(msgs::geometry_msgs::Quaternion &quaternion, const web::json::value &response, bool is_sub_json = false);

  static PointTuple toVector3(const web::json::value &response, bool is_sub_json = false);

  static void toHeader(msgs::std_msgs::Header &header, const web::json::value &response, bool is_sub_json = false);
};

template <typename T>
T Deserializer::toStdMsg(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;

  T data = static_cast<T>(msg.at("data").as_double());
  return data;
}

template<typename T>
void Deserializer::toArray(std::vector<T> &vec, const web::json::value &response)
{
  const auto& msg = response.at(U("arr")).as_array();
  std::vector<web::json::value> json_vec(msg.cbegin(), msg.cend());
  for (const auto& val: json_vec)
  {
    vec.push_back(static_cast<T>(val.as_double()));
  }
}

template<typename T, unsigned int N>
std::array<T, N> &Deserializer::toArray(const web::json::value &response)
{
  static std::array<T, N> arr;

  const auto &json_arr = response.as_array();
  auto arr_size = std::distance(json_arr.cbegin(), json_arr.cend());

  if (arr_size > N)
  {
    std::fill(std::begin(arr), std::end(arr), NAN);
    std::cerr << "Json array too big\n";
    return arr;
  }

  auto it = json_arr.cbegin();

  std::generate(std::begin(arr), std::end(arr), [&] {
    return static_cast<T>((*it++).as_double());
  });

  return arr;
}

} // namespace ros_bridge_client::util


#endif //ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
