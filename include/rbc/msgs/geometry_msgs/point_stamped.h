//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINTSTAMPEDMESSAGE_HPP
#define ROSBRIDGECLIENT_POINTSTAMPEDMESSAGE_HPP

#include <rbc/msgs/std_msgs/header.h>
#include <rbc/msgs/geometry_msgs/point.h>
#include <rbc/msgs/ros_type_base.h>

namespace rbc::msgs::geometry_msgs
{

struct PointStamped : public ROSTypeBase
{
public:
  PointStamped();

  PointStamped(double x, double y, double z, std::string frame_id = "world");

  explicit PointStamped(const web::json::value &response);

  ~PointStamped() = default;

  std_msgs::Header header;
  Point point;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::PointStamped &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::PointStamped> &p);

#endif //ROSBRIDGECLIENT_POINTSTAMPEDMESSAGE_HPP
