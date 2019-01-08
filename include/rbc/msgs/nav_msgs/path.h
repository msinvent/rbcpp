//
// Created by julian on 08.01.19.
//

#ifndef ROSBRIDGECLIENT_PATH_H
#define ROSBRIDGECLIENT_PATH_H

#include <vector>
#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/pose_stamped.h>

namespace rbc::msgs::nav_msgs
{

struct Path : public ROSTypeBase
{
  explicit Path(std::string frame_id = "world");

  explicit Path(const web::json::value &response);

  ~Path() final = default;

  void add(const geometry_msgs::PoseStamped &pose);
  
  std_msgs::Header header;
  std::vector<geometry_msgs::PoseStamped> poses;
};

} // namespace rbc::msgs::nav_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::nav_msgs::Path &p);

std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<rbc::msgs::nav_msgs::Path> &p);

#endif //ROSBRIDGECLIENT_PATH_H
