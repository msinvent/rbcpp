//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_INT16_H
#define ROSBRIDGECLIENT_INT16_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct Int16 : public StdMsg<int16_t>
{
  Int16();

  explicit Int16(int16_t data);

  explicit Int16(const web::json::value &response);

  ~Int16() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_INT16_H
