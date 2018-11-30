//
// Created by Julian on 20.10.18.
//

#include <ros_bridge_client/utils/serializer.h>

using namespace ros_bridge_client::utils;
using namespace ros_bridge_client::msgs;
using namespace web;

Serializer::Serializer()
  : json_()
{
  json_[U("op")] = json::value::string("publish");
  json_[U("topic")] = json::value::string("/rosbridge/message");
}

web::json::value &Serializer::toJson(const std_msgs::String &string, bool sub_json)
{
  static web::json::value string_json;

  string_json[U("data")] = json::value::string(string.data);

  return not sub_json ? completeJson(string, string_json) : string_json;
}

web::json::value &Serializer::toJson(const std_msgs::Header &header, bool sub_json)
{
  static web::json::value header_json;
  header_json[U("seq")] = json::value(header.seq);

  json::value json_stamp;
  json_stamp[U("sec")] = json::value(header.stamp.sec);
  json_stamp[U("nsec")] = json::value(header.stamp.nsec);

  header_json[U("stamp")] = json_stamp;
  header_json[U("frame_id")] = json::value::string(header.frame_id);

  return not sub_json ? completeJson(header, header_json) : header_json;
}

json::value &Serializer::completeJson(const ROSTypeBase &msg, const web::json::value &sub_json)
{
  json_[U("type")] = json::value::string(msg.rosMsgType());
  json_[U("msg")] = sub_json;
  return json_;
}

const json::value &Serializer::json() const
{
  return json_;
}

web::json::value &Serializer::toJson(const geometry_msgs::Quaternion &quaternion, bool sub_json)
{
  static web::json::value json_quaternion;
  json_quaternion[U("x")] = json::value(quaternion.x);
  json_quaternion[U("y")] = json::value(quaternion.y);
  json_quaternion[U("z")] = json::value(quaternion.z);
  json_quaternion[U("w")] = json::value(quaternion.w);

  return not sub_json ? completeJson(quaternion, json_quaternion) : json_quaternion;
}

web::json::value &Serializer::toJson(const geometry_msgs::PointStamped &point_stamped, bool sub_json)
{
  static json::value point_stamped_json;

  point_stamped_json[U("header")] = toJson(point_stamped.header, true);
  point_stamped_json[U("point")] = toJson(point_stamped.point, true);

  return not sub_json ? completeJson(point_stamped, point_stamped_json) : point_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::Vector3Stamped &vector3_stamped, bool sub_json)
{
  static json::value vector3_stamped_json;

  vector3_stamped_json[U("header")] = toJson(vector3_stamped.header, true);
  vector3_stamped_json[U("vector")] = toJson(vector3_stamped.vector, true);

  return not sub_json ? completeJson(vector3_stamped, vector3_stamped_json) : vector3_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::QuaternionStamped &quaternion_stamped, bool sub_json)
{
  static json::value quaternion_stamped_json;

  quaternion_stamped_json[U("header")] = toJson(quaternion_stamped.header, true);
  quaternion_stamped_json[U("quaternion")] = toJson(quaternion_stamped.quaternion, true);

  return not sub_json ? completeJson(quaternion_stamped, quaternion_stamped_json) : quaternion_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::Pose &pose, bool sub_json)
{
  static json::value pose_json;

  pose_json[U("position")] = toJson(pose.point, true);
  pose_json[U("orientation")] = toJson(pose.quaternion, true);

  return not sub_json ? completeJson(pose, pose_json) : pose_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::PoseStamped &pose_stamped, bool sub_json)
{
  static json::value pose_stamped_json;

  pose_stamped_json[U("header")] = toJson(pose_stamped.header, true);
  pose_stamped_json[U("pose")] = toJson(pose_stamped.pose, true);

  return not sub_json ? completeJson(pose_stamped, pose_stamped_json) : pose_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::Accel &accel, bool sub_json)
{
  static json::value accel_json;

  accel_json[U("linear")] = toJson(accel.linear, true);
  accel_json[U("angular")] = toJson(accel.angular, true);

  return not sub_json ? completeJson(accel, accel_json) : accel_json;

}

web::json::value &Serializer::toJson(const geometry_msgs::AccelStamped &accel_stamped, bool sub_json)
{
  static json::value accel_stamped_json;

  accel_stamped_json[U("header")] = toJson(accel_stamped.header, true);
  accel_stamped_json[U("accel")] = toJson(accel_stamped.accel, true);

  return not sub_json ? completeJson(accel_stamped, accel_stamped_json) : accel_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::Inertia &inertia, bool sub_json)
{
  static json::value inertia_json;

  inertia_json[U("m")] = json::value(inertia.m);
  inertia_json[U("ixx")] = json::value(inertia.ixx);
  inertia_json[U("ixy")] = json::value(inertia.ixy);
  inertia_json[U("ixz")] = json::value(inertia.ixz);
  inertia_json[U("iyy")] = json::value(inertia.iyy);
  inertia_json[U("iyz")] = json::value(inertia.iyz);
  inertia_json[U("izz")] = json::value(inertia.izz);

  inertia_json[U("com")] = toJson(inertia.com, true);

  return not sub_json ? completeJson(inertia, inertia_json) : inertia_json;
}

web::json::value &Serializer::toJson(const msgs::geometry_msgs::InertiaStamped &inertia_stamped, bool sub_json)
{
  static json::value inertia_stamped_json;

  inertia_stamped_json[U("header")] = toJson(inertia_stamped.header, true);
  inertia_stamped_json[U("inertia")] = toJson(inertia_stamped.inertia, true);

  return not sub_json ? completeJson(inertia_stamped, inertia_stamped_json) : inertia_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::Wrench &wrench, bool sub_json)
{
  static json::value wrench_json;

  wrench_json[U("force")] = toJson(wrench.force, true);
  wrench_json[U("torque")] = toJson(wrench.torque, true);

  return not sub_json ? completeJson(wrench, wrench_json) : wrench_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::WrenchStamped &wrench_stamped, bool sub_json)
{
  static json::value wrench_stamped_json;

  wrench_stamped_json[U("header")] = toJson(wrench_stamped.header, true);
  wrench_stamped_json[U("wrench")] = toJson(wrench_stamped.wrench, true);

  return not sub_json ? completeJson(wrench_stamped, wrench_stamped_json) : wrench_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::Transform &transform, bool sub_json)
{
  static json::value transform_json;

  transform_json[U("translation")] = toJson(transform.translation, true);
  transform_json[U("rotation")] = toJson(transform.rotation, true);

  return not sub_json ? completeJson(transform, transform_json) : transform_json;
}

web::json::value &Serializer::toJson(const msgs::geometry_msgs::TransformStamped &transform_stamped, bool sub_json)
{
  static json::value transform_stamped_json;

  transform_stamped_json[U("header")] = toJson(transform_stamped.header, true);
  transform_stamped_json[U("transform")] = toJson(transform_stamped.transform, true);

  return not sub_json ? completeJson(transform_stamped, transform_stamped_json) : transform_stamped_json;
}

web::json::value &Serializer::toJson(const geometry_msgs::TwistStamped &twist_stamped, bool sub_json)
{
  static json::value twist_stamped_json;

  twist_stamped_json[U("header")] = toJson(twist_stamped.header, true);
  twist_stamped_json[U("twist")] = toJson(twist_stamped.twist, true);

  return not sub_json ? completeJson(twist_stamped, twist_stamped_json) : twist_stamped_json;
}

web::json::value &Serializer::toJson(const msgs::geometry_msgs::Pose2D &pose2d, bool sub_json)
{
  static web::json::value json_pose2d;

  json_pose2d[U("x")] = web::json::value(pose2d.x);
  json_pose2d[U("y")] = web::json::value(pose2d.y);
  json_pose2d[U("theta")] = web::json::value(pose2d.theta);

  return not sub_json ? completeJson(pose2d, json_pose2d) : json_pose2d;
}

web::json::value &Serializer::toJson(const std_msgs::ColorRGBA &rgba, bool sub_json)
{
  static web::json::value json_rgba;

  json_rgba[U("r")] = web::json::value(rgba.r);
  json_rgba[U("g")] = web::json::value(rgba.g);
  json_rgba[U("b")] = web::json::value(rgba.b);
  json_rgba[U("a")] = web::json::value(rgba.a);

  return not sub_json ? completeJson(rgba, json_rgba) : json_rgba;
}

web::json::value &Serializer::toJson(const geometry_msgs::TwistWithCovariance &twist_cov, bool sub_json)
{
  static web::json::value json_twist_cov;

  json_twist_cov[U("twist")] = toJson(twist_cov.twist, true);
  json_twist_cov[U("covariance")] = web::json::value::array(toJsonArray<double, 36>(twist_cov.covariance));

  return not sub_json ? completeJson(twist_cov, json_twist_cov) : json_twist_cov;
}

web::json::value &Serializer::toJson(const geometry_msgs::TwistWithCovarianceStamped &twist_st_cov, bool sub_json)
{
  static web::json::value json_twist_cov;

  json_twist_cov[U("twist")] = toJson(twist_st_cov.twist, true);
  json_twist_cov[U("header")] = toJson(twist_st_cov.header, true);

  return not sub_json ? completeJson(twist_st_cov, json_twist_cov) : json_twist_cov;
}

web::json::value &Serializer::toJson(const geometry_msgs::PoseWithCovariance &pose_cov, bool sub_json)
{
  static web::json::value json_pose_cov;

  json_pose_cov[U("pose")] = toJson(pose_cov.pose, true);
  json_pose_cov[U("covariance")] = web::json::value::array(toJsonArray<double, 36>(pose_cov.covariance));

  return not sub_json ? completeJson(pose_cov, json_pose_cov) : json_pose_cov;
}

web::json::value &Serializer::toJson(const geometry_msgs::PoseWithCovarianceStamped &pose_cov_stamp, bool sub_json)
{
  static web::json::value json_pose_stamp_cov;

  json_pose_stamp_cov[U("pose")] = toJson(pose_cov_stamp.pose, true);
  json_pose_stamp_cov[U("header")] = toJson(pose_cov_stamp.header, true);

  return not sub_json ? completeJson(pose_cov_stamp, json_pose_stamp_cov) : json_pose_stamp_cov;
}
