//
// Created by Julian on 22.10.18.
//

#include <rbc/utils/deserializer.h>
#include <rbc/msgs/std_msgs/color_rgba.h>
#include <rbc/msgs/geometry_msgs/inertia.h>
#include <rbc/msgs/geometry_msgs/pose2d.h>
#include <thread>

using namespace rbc::utils;
using namespace rbc::msgs;

void Deserializer::deserialize(rbc::msgs::geometry_msgs::Pose2D &pose, const web::json::value &response,
                               bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  pose.x = msg.at(U("x")).as_double();
  pose.y = msg.at(U("y")).as_double();
  pose.theta = msg.at(U("theta")).as_double();
}

void Deserializer::deserialize(rbc::msgs::std_msgs::Header &header, const web::json::value &response,
                               bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  header.seq = msg.at(U("seq")).as_double();
  header.stamp.sec = msg.at(U("stamp")).at(U("secs")).as_double();
  header.stamp.nsec = msg.at(U("stamp")).at(U("nsecs")).as_double();
  header.frame_id = msg.at(U("frame_id")).as_string();
}

void Deserializer::deserialize(msgs::geometry_msgs::Quaternion &quaternion, const web::json::value &response,
                               bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  quaternion.x = msg.at(U("x")).as_double();
  quaternion.y = msg.at(U("y")).as_double();
  quaternion.z = msg.at(U("z")).as_double();
  quaternion.w = msg.at(U("w")).as_double();
}

void Deserializer::deserialize(msgs::geometry_msgs::Inertia &inertia, const web::json::value &response,
                               bool is_sub_json)
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

void Deserializer::deserialize(rbc::msgs::std_msgs::ColorRGBA &color, const web::json::value &response,
                               bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  color.r = static_cast<float>(msg.at(U("r")).as_double());
  color.g = static_cast<float>(msg.at(U("g")).as_double());
  color.b = static_cast<float>(msg.at(U("b")).as_double());
  color.a = static_cast<float>(msg.at(U("a")).as_double());
}

void Deserializer::deserialize(std::string &str, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  str = msg.at(U("data")).as_string();
}

std::string Deserializer::toString(const web::json::value &json)
{
  utility::stringstream_t stream;
  json.serialize(stream);
  return stream.str();
}

void Deserializer::deserialize(geometry_msgs::Polygon &polygon, const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  deserialize(polygon.points, msg, "points");
}

void Deserializer::deserialize(geometry_msgs::Pose &pose, const web::json::value &response, bool is_sub_json)
{
  deserialize(pose.point, response.at("position"), true);
  deserialize(pose.orientation, response.at("orientation"), true);
}
