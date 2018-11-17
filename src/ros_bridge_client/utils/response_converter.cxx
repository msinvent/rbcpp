//
// Created by Julian on 22.10.18.
//

#include <ros_bridge_client/utils/response_converter.h>
#include <ros_bridge_client/msgs/rbc_message.h>

using namespace ros_bridge_client::utils;
using namespace ros_bridge_client::msgs;

PointTuple ResponseConverter::responseToPoint(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &z = msg.at(U("z")).as_double();
  return std::forward_as_tuple(x, y, z);
}

PointTuple ResponseConverter::responseToPose2D(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &theta = msg.at(U("theta")).as_double();
  return std::forward_as_tuple(x, y, theta);
}

Point32Tuple ResponseConverter::responseToPoint32(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = static_cast<float>(msg.at(U("x")).as_double());
  const double &y = static_cast<float>(msg.at(U("y")).as_double());
  const double &z = static_cast<float>(msg.at(U("z")).as_double());
  return std::forward_as_tuple(x, y, z);
}

HeaderTuple ResponseConverter::responseToHeader(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &seq = msg.at(U("seq")).as_double();
  const double &stamp_sec = msg.at(U("stamp")).at(U("secs")).as_double();
  const double &stamp_nsec = msg.at(U("stamp")).at(U("nsecs")).as_double();
  const std::string &frame = msg.at(U("frame_id")).as_string();
  return std::forward_as_tuple(seq, stamp_sec, stamp_nsec, frame);
}

PointTuple ResponseConverter::responseToVector3(const web::json::value &response, bool is_sub_json)
{
  return responseToPoint(response, is_sub_json);
}

QuaternionTuple ResponseConverter::responseToQuaternion(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const double &x = msg.at(U("x")).as_double();
  const double &y = msg.at(U("y")).as_double();
  const double &z = msg.at(U("z")).as_double();
  const double &w = msg.at(U("w")).as_double();
  return std::forward_as_tuple(x, y, z, w);
}

InertiaTuple ResponseConverter::responseToInertia(const web::json::value &response, bool is_sub_json)
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
