//
// Created by Julian on 22.10.18.
//

#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::utils;
using namespace ros_bridge_client::msgs;

PointTuple Deserializer::toPoint(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &z = msg.at(U("z")).as_double();
  return std::forward_as_tuple(x, y, z);
}

PointTuple Deserializer::toPose2D(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &theta = msg.at(U("theta")).as_double();
  return std::forward_as_tuple(x, y, theta);
}

Point32Tuple Deserializer::toPoint32(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = static_cast<float>(msg.at(U("x")).as_double());
  const double &y = static_cast<float>(msg.at(U("y")).as_double());
  const double &z = static_cast<float>(msg.at(U("z")).as_double());
  return std::forward_as_tuple(x, y, z);
}

void Deserializer::toHeader(ros_bridge_client::msgs::std_msgs::Header &header, const web::json::value &response,
                            bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  header.seq = msg.at(U("seq")).as_double();
  header.stamp.sec = msg.at(U("stamp")).at(U("secs")).as_double();
  header.stamp.nsec = msg.at(U("stamp")).at(U("nsecs")).as_double();
  header.frame_id = msg.at(U("frame_id")).as_string();
}

PointTuple Deserializer::toVector3(const web::json::value &response, bool is_sub_json)
{
  return toPoint(response, is_sub_json);
}

QuaternionTuple Deserializer::toQuaternion(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &z = msg.at(U("z")).as_double();
  const double &w = msg.at(U("w")).as_double();
  return std::forward_as_tuple(x, y, z, w);
}

InertiaTuple Deserializer::toInertia(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;

  const double &m = msg.at(U("m")).as_double();
  const double &ixx = msg.at(U("ixx")).as_double();
  const double &ixy = msg.at(U("ixy")).as_double();
  const double &ixz = msg.at(U("ixz")).as_double();
  const double &iyy = msg.at(U("iyy")).as_double();
  const double &iyz = msg.at(U("iyz")).as_double();
  const double &izz = msg.at(U("izz")).as_double();

  return std::forward_as_tuple(m, ixx, ixy, ixz, iyy, iyz, izz);
}

ColorTuple Deserializer::toColor(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const float &r = static_cast<float>(msg.at(U("r")).as_double());
  const float &g = static_cast<float>(msg.at(U("g")).as_double());
  const float &b = static_cast<float>(msg.at(U("b")).as_double());
  const float &a = static_cast<float>(msg.at(U("a")).as_double());
  return std::forward_as_tuple(r, g, b, a);
}

const std::string &Deserializer::toString(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const std::string &s = msg.at(U("data")).as_string();
  return s;
}

const std::string Deserializer::convToString(const web::json::value &json)
{
  utility::stringstream_t stream;
  json.serialize(stream);
  return stream.str();
}

std::vector<geometry_msgs::Point32> &Deserializer::toPolygon(const web::json::value &response)
{
  static std::vector<geometry_msgs::Point32> points;
  points.clear();
  const auto &json_arr = response.as_array();
  auto arr_size = std::distance(json_arr.cbegin(), json_arr.cend());
  points.reserve(arr_size);

  auto it = json_arr.cbegin();
  std::generate(std::begin(points), std::end(points), [&]
  {
      auto[x, y, z] = Deserializer::toPoint32(*it++);
      return geometry_msgs::Point32(x, y, z);
  });

  return points;
}

void Deserializer::toPolygonStamped(std::vector<geometry_msgs::Point32> &points, std_msgs::Header &header,
                                    const web::json::value &response)
{
  const auto &msg = response.at(U("msg"));
  points = toPolygon(msg.at(U("polygon")).at(U("points")));

  toHeader(header, msg.at(U("header")), true);
}

