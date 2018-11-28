//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <ros_bridge_client/utils/json_creator.h>
#include <ros_bridge_client/utils/response_converter.h>

int main(void)
{
  std::vector<int> x{1, 2};
  ros_bridge_client::utils::JsonCreator c;
  const auto &j = c.toJson(x);
  std::cout << j;
  std::vector<int> response;
  ros_bridge_client::utils::ResponseConverter::responseToArray(response, j);
  std::copy(std::begin(response), std::end(response), std::ostream_iterator<int>(std::cout, " "));
}