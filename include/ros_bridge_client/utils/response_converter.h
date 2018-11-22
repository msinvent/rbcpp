//
// Created by Julian on 22.10.18.
//

#ifndef ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
#define ROSBRIDGECLIENT_RESPONSE_CONVERTER_H

#include <cpprest/json.h>
#include <tuple>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>

namespace ros_bridge_client::utils
{

using PointTuple = std::tuple<double, double, double>;
using ColorTuple = std::tuple<float, float, float, float>;
using InertiaTuple = std::tuple<double, double, double, double, double, double, double>;
using PoseTuple = std::tuple<msgs::geometry_msgs::Point, msgs::geometry_msgs::Quaternion>;
using Point32Tuple = std::tuple<float, float, float>;
using QuaternionTuple = std::tuple<double, double, double, double>;
using HeaderTuple = std::tuple<double, double, double, std::string>;

struct ResponseConverter
{
  template <typename T>
  static T responseToStdMsg(const web::json::value &response, std::string data_type, bool is_sub_json = false);

  static ColorTuple responseToColor(const web::json::value &response, bool is_sub_json = false);

  static PointTuple responseToPoint(const web::json::value &response, bool is_sub_json = false);
  
  static PointTuple responseToPose2D(const web::json::value &response, bool is_sub_json = false);

  static InertiaTuple responseToInertia(const web::json::value &response, bool is_sub_json = false);

  static Point32Tuple responseToPoint32(const web::json::value &response, bool is_sub_json = false);

  static QuaternionTuple responseToQuaternion(const web::json::value &response, bool is_sub_json = false);

  static PointTuple responseToVector3(const web::json::value &response, bool is_sub_json = false);

  static HeaderTuple responseToHeader(const web::json::value &response, bool is_sub_json = false);
};

template <typename T>
T ResponseConverter::responseToStdMsg(const web::json::value &response, std::string data_type, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;

  if (data_type == "string")
  {
    T data = msg.at(U("data")).as_string();
    return data;
  }

  T data = msg.at(U("msg")).as_string();
  return data;
}

} // namespace ros_bridge_client::utils


#endif //ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
