//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_POINT_HPP
#define ROSBRIDGECLIENT_POINT_HPP

namespace rbc
{
namespace ros_types
{

struct Point32
{
  float x;
  float y;
  float z;
};

struct Point
{
  double x;
  double y;
  double z;
};

struct Pose2D
{
  double x;
  double y;
  double theta;
};

struct ColorRGBA
{
  float r;
  float g;
  float b;
  float a;
};

struct Vector3 : public Point
{
};

struct Quaternion : public Point
{
  double w;
};

struct Pose
{
  Point p;
  Quaternion q;
};

} // namespace ros_types
} // namespace rbc

#endif //ROSBRIDGECLIENT_POINT_HPP
