//
// Created by Julian on 22.10.18.
//

#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/std_msgs/color_rgba.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>

using namespace ros_bridge_client::utils;
using namespace ros_bridge_client::msgs;

PointTuple Deserializer::toPose2D(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &theta = msg.at(U("theta")).as_double();
  return std::forward_as_tuple(x, y, theta);
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

void Deserializer::toQuaternion(msgs::geometry_msgs::Quaternion &quaternion, const web::json::value &response,
                                bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  quaternion.x = msg.at(U("x")).as_double();
  quaternion.y = msg.at(U("y")).as_double();
  quaternion.z = msg.at(U("z")).as_double();
  quaternion.w = msg.at(U("w")).as_double();
}

void Deserializer::toInertia(msgs::geometry_msgs::Inertia &inertia, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;

  inertia.m = msg.at(U("m")).as_double();
  inertia.ixx = msg.at(U("ixx")).as_double();
  inertia.ixy = msg.at(U("ixy")).as_double();
  inertia.ixz = msg.at(U("ixz")).as_double();
  inertia.iyy = msg.at(U("iyy")).as_double();
  inertia.iyz = msg.at(U("iyz")).as_double();
  inertia.izz = msg.at(U("izz")).as_double();
}

void Deserializer::toColor(ros_bridge_client::msgs::std_msgs::ColorRGBA &color, const web::json::value &response,
                           bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  color.r = static_cast<float>(msg.at(U("r")).as_double());
  color.g = static_cast<float>(msg.at(U("g")).as_double());
  color.b = static_cast<float>(msg.at(U("b")).as_double());
  color.a = static_cast<float>(msg.at(U("a")).as_double());
}

void Deserializer::toString(std::string &str, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  str = msg.at(U("data")).as_string();
}

const std::string Deserializer::convToString(const web::json::value &json)
{
  utility::stringstream_t stream;
  json.serialize(stream);
  return stream.str();
}

void Deserializer::toPolygon(msgs::geometry_msgs::Polygon &polygon, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const auto &json_arr = msg.at(U("points")).as_array();

  auto it = json_arr.cbegin();
  std::generate(std::begin(polygon.points), std::end(polygon.points), [&]
  {
      geometry_msgs::Point32 p;
      Deserializer::toXYZ<float>(p, *it++);
      return p;
  });
}

