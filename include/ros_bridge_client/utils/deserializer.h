//
// Created by Julian on 22.10.18.
//

#ifndef ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
#define ROSBRIDGECLIENT_RESPONSE_CONVERTER_H

#include <cpprest/json.h>
#include <tuple>
#include <vector>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/std_msgs/std_msg.h>
#include <ros_bridge_client/msgs/std_msgs/color_rgba.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose2d.h>
#include <ros_bridge_client/msgs/xyzmessage.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>
#include <ros_bridge_client/msgs/geometry_msgs/polygon.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>

namespace ros_bridge_client::utils
{

struct Deserializer
{
  template<typename T>
  static void toXYZ(msgs::XYZMessage<T> &xyz, const web::json::value &response, bool is_sub_json = false);

  template<typename T>
  static void toStdMsg(msgs::std_msgs::StdMsg<T> &std, const web::json::value &response, bool is_sub_json = false);

  template<typename T>
  static void toVector(std::vector<T> &vec, const web::json::value &response, std::string key = "arr");

  template<typename T, unsigned int N>
  static void toArray(std::array<T, N> &array, const web::json::value &response);

  static std::string toString(const web::json::value &response);

  static void toString(std::string &str, const web::json::value &response, bool is_sub_json = false);

  static void toPolygon(msgs::geometry_msgs::Polygon &polygon, const web::json::value &response, bool is_sub_json = false);

  static void toColor(msgs::std_msgs::ColorRGBA &color, const web::json::value &response, bool is_sub_json = false);

  static void toPose2D(msgs::geometry_msgs::Pose2D &pose, const web::json::value &response, bool is_sub_json = false);

  static void
  toInertia(msgs::geometry_msgs::Inertia &inertia, const web::json::value &response, bool is_sub_json = false);

  static void
  toQuaternion(msgs::geometry_msgs::Quaternion &quaternion, const web::json::value &response, bool is_sub_json = false);

  static void toHeader(msgs::std_msgs::Header &header, const web::json::value &response, bool is_sub_json = false);
};

template<typename T>
void Deserializer::toXYZ(msgs::XYZMessage<T> &xyz, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  xyz.x = static_cast<T>(msg.at(U("x")).as_double());
  xyz.y = static_cast<T>(msg.at(U("y")).as_double());
  xyz.z = static_cast<T>(msg.at(U("z")).as_double());
}

template<typename T>
void Deserializer::toStdMsg(msgs::std_msgs::StdMsg<T> &std, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  std.data = static_cast<T>(msg.at("data").as_double());
}

template<typename T>
void Deserializer::toVector(std::vector<T> &vec, const web::json::value &response, std::string key)
{
  const auto &msg = response.at(U(key)).as_array();
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

} // namespace ros_bridge_client::util


#endif //ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
