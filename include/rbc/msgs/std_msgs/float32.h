//
// Created by julian on 18.11.18.
//

#ifndef ROSBRIDGECLIENT_FLOAT32_H
#define ROSBRIDGECLIENT_FLOAT32_H

#include <rbc/msgs/std_msgs/std_msg.h>
#include <cpprest/json.h>

namespace rbc::msgs::std_msgs
{

struct Float32 : public StdMsg<float>
{
  Float32();

  explicit Float32(float data);

  explicit Float32(const web::json::value &response);
  
  ~Float32() final = default;
};

} // namespace rbc::msgs::std_msgs

#endif //ROSBRIDGECLIENT_FLOAT32_H
