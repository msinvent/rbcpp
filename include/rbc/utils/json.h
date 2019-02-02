//
// Created by julian on 02.02.19.
//

#ifndef ROSBRIDGECLIENT_JSON_H
#define ROSBRIDGECLIENT_JSON_H

#include <cpprest/json.h>
#include <tuple>

namespace rbc::utils
{

std::tuple<bool, const web::json::value&> get(const web::json::value &json, std::string key)
{
  static bool result = true;
  try
  {
    return std::make_tuple(result, json.at(U(key)));
  }
  catch (const web::json::json_exception &e)
  {
    std::cout << "Invalid json key: " << key << " for json: " << json << "\n";
    result = false;
    return std::make_tuple(result, std::cref(json));
  }
}

}

#endif //ROSBRIDGECLIENT_JSON_H
