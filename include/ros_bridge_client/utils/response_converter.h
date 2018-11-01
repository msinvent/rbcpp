//
// Created by Julian on 22.10.18.
//

#ifndef ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
#define ROSBRIDGECLIENT_RESPONSE_CONVERTER_H

#include <cpprest/json.h>
#include <tuple>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose.h>


namespace ros_bridge_client
{

namespace utils
{

using PointTuple = std::tuple<double, double, double>;
using PoseTuple = std::tuple<msgs::geometry_msgs::Point, msgs::geometry_msgs::Quaternion>;
using Point32Tuple = std::tuple<float, float, float>;
using QuaternionTuple = std::tuple<double, double, double, double>;
using HeaderTuple = std::tuple<double, double, double, std::string>;

struct ResponseConverter
{
  static PointTuple responseToPoint(const web::json::value &response, bool is_sub_json = false);

  static Point32Tuple responseToPoint32(const web::json::value &response, bool is_sub_json = false);

  static QuaternionTuple responseToQuaternion(const web::json::value &response, bool is_sub_json = false);

  static PointTuple responseToVector3(const web::json::value &response, bool is_sub_json = false);

  static HeaderTuple responseToHeader(const web::json::value &response, bool is_sub_json = false);
};

} // namespace msgs
} // ros_bridge_client


#endif //ROSBRIDGECLIENT_RESPONSE_CONVERTER_H
