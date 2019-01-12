//
// Created by Julian on 20.10.18.
//

#include <rbc/utils/serializer.h>

using namespace rbc::utils;
using namespace rbc::msgs;
using namespace web;

Serializer::Serializer()
    : json_()
{
  json_[U("op")] = json::value::string("publish");
  json_[U("topic")] = json::value::string("/rosbridge/message");
}

web::json::value &Serializer::serialize(const std_msgs::String &string, bool sub_json)
{
  static web::json::value string_json;

  string_json[U("data")] = json::value::string(string.data);

  return not sub_json ? completeJson(string, string_json) : string_json;
}

web::json::value &Serializer::serialize(const std_msgs::Header &header, bool sub_json)
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

web::json::value &Serializer::serialize(const geometry_msgs::Quaternion &quaternion, bool sub_json)
{
  static web::json::value json_quaternion;
  json_quaternion[U("x")] = json::value(quaternion.x);
  json_quaternion[U("y")] = json::value(quaternion.y);
  json_quaternion[U("z")] = json::value(quaternion.z);
  json_quaternion[U("w")] = json::value(quaternion.w);

  return not sub_json ? completeJson(quaternion, json_quaternion) : json_quaternion;
}

web::json::value &Serializer::serialize(const geometry_msgs::PointStamped &point_stamped, bool sub_json)
{
  static json::value point_stamped_json;

  point_stamped_json[U("header")] = serialize(point_stamped.header, true);
  point_stamped_json[U("point")] = serialize(point_stamped.point, true);

  return not sub_json ? completeJson(point_stamped, point_stamped_json) : point_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::Vector3Stamped &vector3_stamped, bool sub_json)
{
  static json::value vector3_stamped_json;

  vector3_stamped_json[U("header")] = serialize(vector3_stamped.header, true);
  vector3_stamped_json[U("vector")] = serialize(vector3_stamped.vector, true);

  return not sub_json ? completeJson(vector3_stamped, vector3_stamped_json) : vector3_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::QuaternionStamped &quaternion_stamped, bool sub_json)
{
  static json::value quaternion_stamped_json;

  quaternion_stamped_json[U("header")] = serialize(quaternion_stamped.header, true);
  quaternion_stamped_json[U("quaternion")] = serialize(quaternion_stamped.quaternion, true);

  return not sub_json ? completeJson(quaternion_stamped, quaternion_stamped_json) : quaternion_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::Pose &pose, bool sub_json)
{
  static json::value pose_json;

  pose_json[U("position")] = serialize(pose.point, true);
  pose_json[U("orientation")] = serialize(pose.orientation, true);

  return not sub_json ? completeJson(pose, pose_json) : pose_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::PoseStamped &pose_stamped, bool sub_json)
{
  static json::value pose_stamped_json;

  pose_stamped_json[U("header")] = serialize(pose_stamped.header, true);
  pose_stamped_json[U("pose")] = serialize(pose_stamped.pose, true);

  return not sub_json ? completeJson(pose_stamped, pose_stamped_json) : pose_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::Accel &accel, bool sub_json)
{
  static json::value accel_json;

  accel_json[U("linear")] = serialize(accel.linear, true);
  accel_json[U("angular")] = serialize(accel.angular, true);

  return not sub_json ? completeJson(accel, accel_json) : accel_json;

}

web::json::value &Serializer::serialize(const geometry_msgs::AccelStamped &accel_stamped, bool sub_json)
{
  static json::value accel_stamped_json;

  accel_stamped_json[U("header")] = serialize(accel_stamped.header, true);
  accel_stamped_json[U("accel")] = serialize(accel_stamped.accel, true);

  return not sub_json ? completeJson(accel_stamped, accel_stamped_json) : accel_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::Inertia &inertia, bool sub_json)
{
  static json::value inertia_json;

  inertia_json[U("m")] = json::value(inertia.m);
  inertia_json[U("ixx")] = json::value(inertia.ixx);
  inertia_json[U("ixy")] = json::value(inertia.ixy);
  inertia_json[U("ixz")] = json::value(inertia.ixz);
  inertia_json[U("iyy")] = json::value(inertia.iyy);
  inertia_json[U("iyz")] = json::value(inertia.iyz);
  inertia_json[U("izz")] = json::value(inertia.izz);

  inertia_json[U("com")] = serialize(inertia.com, true);

  return not sub_json ? completeJson(inertia, inertia_json) : inertia_json;
}

web::json::value &Serializer::serialize(const msgs::geometry_msgs::InertiaStamped &inertia_stamped, bool sub_json)
{
  static json::value inertia_stamped_json;

  inertia_stamped_json[U("header")] = serialize(inertia_stamped.header, true);
  inertia_stamped_json[U("inertia")] = serialize(inertia_stamped.inertia, true);

  return not sub_json ? completeJson(inertia_stamped, inertia_stamped_json) : inertia_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::Wrench &wrench, bool sub_json)
{
  static json::value wrench_json;

  wrench_json[U("force")] = serialize(wrench.force, true);
  wrench_json[U("torque")] = serialize(wrench.torque, true);

  return not sub_json ? completeJson(wrench, wrench_json) : wrench_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::WrenchStamped &wrench_stamped, bool sub_json)
{
  static json::value wrench_stamped_json;

  wrench_stamped_json[U("header")] = serialize(wrench_stamped.header, true);
  wrench_stamped_json[U("wrench")] = serialize(wrench_stamped.wrench, true);

  return not sub_json ? completeJson(wrench_stamped, wrench_stamped_json) : wrench_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::Transform &transform, bool sub_json)
{
  static json::value transform_json;

  transform_json[U("translation")] = serialize(transform.translation, true);
  transform_json[U("rotation")] = serialize(transform.rotation, true);

  return not sub_json ? completeJson(transform, transform_json) : transform_json;
}

web::json::value &Serializer::serialize(const msgs::geometry_msgs::TransformStamped &transform_stamped, bool sub_json)
{
  static json::value transform_stamped_json;

  transform_stamped_json[U("header")] = serialize(transform_stamped.header, true);
  transform_stamped_json[U("transform")] = serialize(transform_stamped.transform, true);

  return not sub_json ? completeJson(transform_stamped, transform_stamped_json) : transform_stamped_json;
}

web::json::value &Serializer::serialize(const geometry_msgs::TwistStamped &twist_stamped, bool sub_json)
{
  static json::value twist_stamped_json;

  twist_stamped_json[U("header")] = serialize(twist_stamped.header, true);
  twist_stamped_json[U("twist")] = serialize(twist_stamped.twist, true);

  return not sub_json ? completeJson(twist_stamped, twist_stamped_json) : twist_stamped_json;
}

web::json::value &Serializer::serialize(const msgs::geometry_msgs::Pose2D &pose2d, bool sub_json)
{
  static web::json::value json_pose2d;

  json_pose2d[U("x")] = web::json::value(pose2d.x);
  json_pose2d[U("y")] = web::json::value(pose2d.y);
  json_pose2d[U("theta")] = web::json::value(pose2d.theta);

  return not sub_json ? completeJson(pose2d, json_pose2d) : json_pose2d;
}

web::json::value &Serializer::serialize(const std_msgs::ColorRGBA &rgba, bool sub_json)
{
  static web::json::value json_rgba;

  json_rgba[U("r")] = web::json::value(rgba.r);
  json_rgba[U("g")] = web::json::value(rgba.g);
  json_rgba[U("b")] = web::json::value(rgba.b);
  json_rgba[U("a")] = web::json::value(rgba.a);

  return not sub_json ? completeJson(rgba, json_rgba) : json_rgba;
}

web::json::value &Serializer::serialize(const geometry_msgs::TwistWithCovariance &twist_cov, bool sub_json)
{
  static web::json::value json_twist_cov;

  json_twist_cov[U("twist")] = serialize(twist_cov.twist, true);
  json_twist_cov[U("covariance")] = web::json::value::array(serializeSingles<double, 36>(twist_cov.covariance));

  return not sub_json ? completeJson(twist_cov, json_twist_cov) : json_twist_cov;
}

web::json::value &Serializer::serialize(const geometry_msgs::TwistWithCovarianceStamped &twist_st_cov, bool sub_json)
{
  static web::json::value json_twist_cov;

  json_twist_cov[U("twist")] = serialize(twist_st_cov.twist, true);
  json_twist_cov[U("header")] = serialize(twist_st_cov.header, true);

  return not sub_json ? completeJson(twist_st_cov, json_twist_cov) : json_twist_cov;
}

web::json::value &Serializer::serialize(const geometry_msgs::PoseWithCovariance &pose_cov, bool sub_json)
{
  static web::json::value json_pose_cov;

  json_pose_cov[U("pose")] = serialize(pose_cov.pose, true);
  json_pose_cov[U("covariance")] = web::json::value::array(serializeSingles<double, 36>(pose_cov.covariance));

  return not sub_json ? completeJson(pose_cov, json_pose_cov) : json_pose_cov;
}

web::json::value &Serializer::serialize(const geometry_msgs::PoseWithCovarianceStamped &pose_cov_stamp, bool sub_json)
{
  static web::json::value json_pose_stamp_cov;

  json_pose_stamp_cov[U("pose")] = serialize(pose_cov_stamp.pose, true);
  json_pose_stamp_cov[U("header")] = serialize(pose_cov_stamp.header, true);

  return not sub_json ? completeJson(pose_cov_stamp, json_pose_stamp_cov) : json_pose_stamp_cov;
}

web::json::value &Serializer::serialize(const geometry_msgs::AccelWithCovariance &accel_cov, bool sub_json)
{
  static web::json::value json_accel_cov;

  json_accel_cov[U("accel")] = serialize(accel_cov.accel, true);
  json_accel_cov[U("covariance")] = web::json::value::array(serializeSingles<double, 36>(accel_cov.covariance));

  return not sub_json ? completeJson(accel_cov, json_accel_cov) : json_accel_cov;
}

web::json::value &Serializer::serialize(const geometry_msgs::AccelWithCovarianceStamped &accel_cov, bool sub_json)
{
  static web::json::value json_accel_stamped_cov;

  json_accel_stamped_cov[U("accel")] = serialize(accel_cov.accel, true);
  json_accel_stamped_cov[U("header")] = serialize(accel_cov.header, true);

  return not sub_json ? completeJson(accel_cov, json_accel_stamped_cov) : json_accel_stamped_cov;
}

web::json::value &Serializer::serialize(const geometry_msgs::Polygon &polygon, bool sub_json)
{
  static web::json::value json_polygon;

  json_polygon[U("points")] = web::json::value::array(serialize(polygon.points));

  return not sub_json ? completeJson(polygon, json_polygon) : json_polygon;
}

web::json::value &Serializer::serialize(const geometry_msgs::PolygonStamped &polygon_stamp, bool sub_json)
{
  static web::json::value json_polygon_stamp;

  json_polygon_stamp[U("polygon")] = serialize(polygon_stamp.polygon, true);
  json_polygon_stamp[U("header")] = serialize(polygon_stamp.header, true);

  return not sub_json ? completeJson(polygon_stamp, json_polygon_stamp) : json_polygon_stamp;
}

web::json::value &Serializer::serialize(const geometry_msgs::PoseArray &pose_arr, bool sub_json)
{
  static web::json::value json_pose_arr;

  json_pose_arr[U("header")] = serialize(pose_arr.header, true);
  json_pose_arr[U("poses")] = web::json::value::array(serialize(pose_arr.poses));

  return not sub_json ? completeJson(pose_arr, json_pose_arr) : json_pose_arr;
}

web::json::value &Serializer::serialize(const nav_msgs::Odometry &odometry, bool sub_json)
{
  static web::json::value odometry_stamp;

  odometry_stamp[U("child_frame_id")] = json::value::string(odometry.child_frame_id);
  odometry_stamp[U("header")] = serialize(odometry.header, true);
  odometry_stamp[U("pose")] = serialize(odometry.pose, true);
  odometry_stamp[U("twist")] = serialize(odometry.twist, true);

  return not sub_json ? completeJson(odometry, odometry_stamp) : odometry_stamp;
}

web::json::value &Serializer::serialize(const sensor_msgs::Imu &imu, bool sub_json)
{
  static web::json::value imu_json;

  imu_json[U("orientation")] = serialize(imu.orientation, true);
  imu_json[U("angular_velocity")] = serialize(imu.angular_velocity, true);
  imu_json[U("linear_acceleration")] = serialize(imu.linear_acceleration, true);
  imu_json[U("linear_acceleration_covariance")] = web::json::value::array(
      serializeSingles<float, 9>(imu.linear_acceleration_covariance));
  imu_json[U("angular_velocity_covariance")] = web::json::value::array(
      serializeSingles<float, 9>(imu.angular_velocity_covariance));
  imu_json[U("orientation_covariance")] = web::json::value::array(serializeSingles<float, 9>(imu.orientation_covariance));

  return not sub_json ? completeJson(imu, imu_json) : imu_json;
}

web::json::value &Serializer::serialize(const sensor_msgs::Joy &joy, bool sub_json)
{
  static web::json::value joy_json;

  joy_json[U("header")] = serialize(joy.header, true);
  joy_json[U("axes")] = web::json::value::array(serializeSingles(joy.axes));
  joy_json[U("buttons")] = web::json::value::array(serializeSingles(joy.buttons));

  return not sub_json ? completeJson(joy, joy_json) : joy_json;
}

web::json::value &Serializer::serialize(const sensor_msgs::Temperature &temp, bool sub_json)
{
  static web::json::value temp_json;

  temp_json[U("header")] = serialize(temp.header, true);
  temp_json[U("temperature")] = web::json::value(temp.temperature);
  temp_json[U("variance")] = web::json::value(temp.variance);

  return not sub_json ? completeJson(temp, temp_json) : temp_json;
}

web::json::value &Serializer::serialize(const JointState &joint_state, bool sub_json)
{
  static web::json::value joint_state_json;

  joint_state_json[U("header")] = serialize(joint_state.header, true);
  joint_state_json[U("name")] = web::json::value::array(serializeSinglesStr(joint_state.name));
  joint_state_json[U("position")] = web::json::value::array(serializeSingles(joint_state.position));
  joint_state_json[U("velocity")] = web::json::value::array(serializeSingles(joint_state.velocity));
  joint_state_json[U("effort")] = web::json::value::array(serializeSingles(joint_state.effort));

  return not sub_json ? completeJson(joint_state, joint_state_json) : joint_state_json;
}

std::vector<web::json::value> &Serializer::serializeSinglesStr(const std::vector<std::string> &vec)
{
  static std::vector<web::json::value> array;
  array.clear();
  array.reserve(vec.size());

  for (const auto& str: vec)
  {
    array.push_back(web::json::value::string(str));
  }

  return array;
}

web::json::value &Serializer::serialize(const sensor_msgs::FluidPressure &fp, bool sub_json)
{
  static web::json::value fluid_json;

  fluid_json[U("header")] = serialize(fp.header, true);
  fluid_json[U("fluid_pressure")] = web::json::value(fp.fluid_pressure);
  fluid_json[U("variance")] = web::json::value(fp.variance);

  return not sub_json ? completeJson(fp, fluid_json) : fluid_json;
}

web::json::value &Serializer::serialize(const nav_msgs::Path &p, bool sub_json)
{
  static web::json::value path_json;

  path_json[U("header")] = serialize(p.header, true);
  path_json[U("poses")] = web::json::value::array(serialize<geometry_msgs::PoseStamped>(p.poses));

  return not sub_json ? completeJson(p, path_json) : path_json;
}
