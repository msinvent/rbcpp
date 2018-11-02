//
// Created by julian on 02.11.18.
//

#include <ros_bridge_client/msgs/geometry_msgs/inertia.h>
#include <ros_bridge_client/utils/response_converter.h>


using namespace ros_bridge_client::msgs::geometry_msgs;


Inertia::Inertia()
  : MessageBase("geometry_msgs/Inertia"),
    m(0),
    ixx(0), ixy(0), ixz(0),
    iyy(0), iyz(0), izz(0),
    com(0, 0, 0)
{}

Inertia::Inertia(double m, const Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz, double izz)
  : MessageBase("geometry_msgs/Inertia"),
    m(m),
    ixx(ixx), ixy(ixy), ixz(ixz),
    iyy(iyy), iyz(iyz), izz(izz),
    com(com)
{}

Inertia::Inertia(const web::json::value &response)
  : MessageBase("geometry_msgs/Inertia"),
    m(0),
    ixx(0), ixy(0), ixz(0),
    iyy(0), iyz(0), izz(0),
    com(0, 0, 0)
{
  std::tie(m, ixx, ixy, ixz, iyy, iyz, izz) = utils::ResponseConverter::responseToInertia(response);
  std::tie(com.x, com.y, com.z) = utils::ResponseConverter::responseToVector3(response.at(U("com")), true);
}
