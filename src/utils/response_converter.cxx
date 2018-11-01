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
  const auto &x = msg.at(U("x")).as_double();
  const auto &y = msg.at(U("y")).as_double();
  const auto &z = msg.at(U("z")).as_double();
  return std::forward_as_tuple(x, y, z);
}

Point32Tuple ResponseConverter::responseToPoint32(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const auto &x = static_cast<float>(msg.at(U("x")).as_double());
  const auto &y = static_cast<float>(msg.at(U("y")).as_double());
  const auto &z = static_cast<float>(msg.at(U("z")).as_double());
  return std::forward_as_tuple(x, y, z);
}


HeaderTuple ResponseConverter::responseToHeader(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const auto &seq = msg.at(U("seq")).as_double();
  const auto &stamp_sec = msg.at(U("stamp")).at(U("secs")).as_double();
  const auto &stamp_nsec = msg.at(U("stamp")).at(U("nsecs")).as_double();
  const auto &frame = msg.at(U("frame_id")).as_string();
  return std::forward_as_tuple(seq, stamp_sec, stamp_nsec, frame);
}

PointTuple ResponseConverter::responseToVector3(const web::json::value &response, bool is_sub_json)
{
  return responseToPoint(response, is_sub_json);
}

QuaternionTuple ResponseConverter::responseToQuaternion(const web::json::value &response, bool is_sub_json)
{
  const auto &msg = not is_sub_json ? response.at(U("msg")) : response;
  const auto &x = msg.at(U("x")).as_double();
  const auto &y = msg.at(U("y")).as_double();
  const auto &z = msg.at(U("z")).as_double();
  const auto &w = msg.at(U("w")).as_double();
  return std::forward_as_tuple(x, y, z, w);
}
