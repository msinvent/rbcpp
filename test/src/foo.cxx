//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <array>
#include <iostream>
#include <iterator>
#include <ros_bridge_client/utils/serializer.h>
#include <ros_bridge_client/utils/deserializer.h>
#include <ros_bridge_client/msgs/geometry_msgs/util/covariance.h>

//std::ostream& operator<<(std::ostream& os, std::array<float, 2> &arr)
//{
//  return os << arr[1];
//}

struct b;

struct a
{
    b& add()
    {
      static b bb(*this);
      return bb;
    }
    int x = 5;
};

struct b
{
    b(const a &aa)
    : d(a.x),
      a(aa)
    {
      std::cout << d;
    }

    int d;
    const a &a;
};
int main(void)
{
}