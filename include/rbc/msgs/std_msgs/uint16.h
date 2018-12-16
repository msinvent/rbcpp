//
// Created by julian on 116.11.116.
//

#ifndef ROSBRIDGECLIENT_UINT16_H
#define ROSBRIDGECLIENT_UINT16_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct UInt16 : public StdMsg<uint16_t>
{
  UInt16();

  explicit UInt16(uint16_t data);

  explicit UInt16(const web::json::value &response);

  ~UInt16() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_UINT16_H
