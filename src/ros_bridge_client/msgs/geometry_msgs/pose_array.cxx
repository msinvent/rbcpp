//
// Created by julian on 11.12.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/pose_array.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseArray::PoseArray(std::string frame_id)
  : ROSTypeBase("geometry_msgs/PoseArray"),
    header(frame_id),
    poses()
{}

PoseArray::PoseArray(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/PoseArray"),
      header(),
      poses()
{
  const auto &msg = response.at(U("msg"));
  const auto &pose_arr_msg = msg.at(U("poses"));

  utils::Deserializer::deserialize(header, msg.at(U("header")), true);
  utils::Deserializer::deserialize(poses, pose_arr_msg.as_array());
}

void PoseArray::add(const Pose &pose)
{
  poses.emplace_back(pose);
}
