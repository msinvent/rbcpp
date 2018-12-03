//
// Created by Julian on 27.10.18.
//

#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance_stamped.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

PoseWithCovarianceStamped::PoseWithCovarianceStamped()
    : ROSTypeBase("geometry_msgs/PoseWithCovarianceStamped"),
      pose(),
      header()
{}

PoseWithCovarianceStamped::PoseWithCovarianceStamped(const Point &p, const Quaternion &q,
                                                     const std::array<double, 36> &arr, std::string frame_id)
    : ROSTypeBase("geometry_msgs/PoseWithCovarianceStamped"),
      pose(p, q, arr),
      header(frame_id)
{}

PoseWithCovarianceStamped::PoseWithCovarianceStamped(const Pose &pose, const std::array<double, 36> &arr,
                                                     std::string frame_id)
    : ROSTypeBase("geometry_msgs/PoseWithCovarianceStamped"),
      pose(pose, arr),
      header(frame_id)
{}


PoseWithCovarianceStamped::PoseWithCovarianceStamped(const PoseWithCovariance &pose, std::string frame_id)
    : ROSTypeBase("geometry_msgs/PoseWithCovarianceStamped"),
      pose(pose),
      header(frame_id)
{}

PoseWithCovarianceStamped::PoseWithCovarianceStamped(const web::json::value &response)
    : ROSTypeBase("geometry_msgs/PoseWithCovarianceStamped"),
      pose(),
      header()
{
  try
  {
    const auto &msg = response.at(U("msg"));
    const auto &pose_base_msg = msg.at(U("pose"));
    const auto &pose_msg = pose_base_msg.at(U("pose"));
    const auto &cov_msg = pose_base_msg.at(U("covariance"));
    const auto &header_msg = msg.at(U("header"));

    utils::Deserializer::toXYZ<double>(pose.pose.point, pose_msg.at(U("position")), true);

    utils::Deserializer::toQuaternion(pose.pose.orientation, pose_msg.at(U("orientation")), true);

    pose.covariance = utils::Deserializer::toArray<double, 36>(cov_msg);

    utils::Deserializer::toHeader(header, header_msg, true);
  } catch(const std::exception &e) {
    std::cerr << "Can't deserialize response (PoseWithCovarianceStamped). May be malformed. \n" << e.what() << "\n";
  }
}

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::PoseWithCovarianceStamped &p)
{
  os << "\nPose With Covariance Stamped:";
  os << p.header;
  os << p.pose;
  os << util::Covariance<double, 36>(p.pose.covariance);
  os << "\n";
  return os;
}

std::ostream &
operator<<(std::ostream &os,
           const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::PoseWithCovarianceStamped> &p)
{
  return os << p.get();
}
