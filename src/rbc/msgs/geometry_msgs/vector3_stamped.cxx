//
// Created by Julian on 18.09.18.
//

#include <rbc/msgs/geometry_msgs/vector3_stamped.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;
using namespace web;

Vector3Stamped::Vector3Stamped(const double x, const double y, const double z, std::string frame_id)
  : ROSTypeBase("geometry_msgs/Vector3Stamped"),
    header(frame_id),
    vector(x, y, z)
{}

Vector3Stamped::Vector3Stamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/Vector3Stamped"),
    header(),
    vector()
{
  utils::Deserializer::deserialize(header, response.at(U("msg")).at(U("header")), true);

  utils::Deserializer::deserialize(vector, response.at(U("msg")).at(U("vector")), true);
}

Vector3Stamped::Vector3Stamped()
  : ROSTypeBase("geometry_msgs/Vector3Stamped"),
    header(),
    vector()
{}

std::ostream &operator<<(std::ostream &os, const Vector3Stamped &p)
{
  os << "\nVector3 Stamped:";
  os << p.header;
  os << p.vector;
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<Vector3Stamped> &p)
{
  return os << *p.get();
}