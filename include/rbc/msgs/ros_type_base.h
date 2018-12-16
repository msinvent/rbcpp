//
// Created by Julian on 20.10.18.
//

#ifndef ROSBRIDGECLIENT_MESSAGE_BASE_H
#define ROSBRIDGECLIENT_MESSAGE_BASE_H

#include <string>

namespace rbc::msgs
{

struct ROSTypeBase
{
  virtual ~ROSTypeBase() = default;

  const std::string &rosMsgType() const;

protected:
  ROSTypeBase() = delete;
  explicit ROSTypeBase(std::string ros_msg_type);

private:
  std::string ros_msg_type;
};

} // namespace rbc::msgs

#endif //ROSBRIDGECLIENT_MESSAGE_BASE_H
