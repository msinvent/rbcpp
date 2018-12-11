//
// Created by Julian on 18.09.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/utils/deserializer.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

Point32::Point32()
  : XYZMessage<float>("geometry_msgs/Point32")
{}

Point32::Point32(float x, float y, float z)
  : XYZMessage<float>("geometry_msgs/Point32", x, y, z)
{}

Point32::Point32(const web::json::value &response)
  : XYZMessage<float>("geometry_msgs/Point32")
{
  utils::Deserializer::deserialize<float>(*this, response, false);
}

std::ostream &operator<<(std::ostream &os, const Point32 &p)
{
  os << "\nPoint32:";
  os << "\n\tx: " << p.x;
  os << "\n\ty: " << p.y;
  os << "\n\tz: " << p.z;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Point32> &p)
{
  return os << *p.get();
}
