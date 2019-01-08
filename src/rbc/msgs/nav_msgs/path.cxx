//
// Created by julian on 08.01.19.
//

#include <rbc/msgs/nav_msgs/path.h>

using namespace rbc::msgs::nav_msgs;

Path::Path(std::string frame_id)
  : ROSTypeBase("nav_msgs/Path"),
    header(frame_id),
    poses()
{
  poses.reserve(200);
}

Path::Path(const web::json::value &response)
    : ROSTypeBase("nav_msgs/Path"),
      header(),
      poses()
{
  poses.reserve(200);

  poses.shrink_to_fit();
}

void Path::add(const rbc::msgs::geometry_msgs::PoseStamped &pose)
{
  poses.push_back(pose);
}

std::ostream &operator<<(std::ostream &os, const rbc::msgs::nav_msgs::Path &p)
{
  os << "Path";
  os << p.header;
  for (const auto &i: p.poses)
  {
    os << "\nPose Stamped";
    os << p.header;
    os << i;
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::nav_msgs::Path> &p)
{
  return os << *p.get();
}
