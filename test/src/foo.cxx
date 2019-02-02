//
// Created by julian on 26.11.18.
//

#include <cpprest/json.h>
#include <array>
#include <iostream>
#include <iterator>
#include <rbc/msgs/geometry_msgs/polygon.h>
#include <rbc/utils/serializer.h>
#include <rbc/utils/deserializer.h>
#include <rbc/msgs/geometry_msgs/util/covariance.h>

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
    return std::make_tuple(result, json);
  }
}


template< typename T >
struct A
{
  static void foo(){ std::cout<< "value" << std::endl; }
};

template< typename T >
struct A< T&>
{
  static void foo(){ std::cout<< "reference" << std::endl; }
};

template< typename T >
struct A< T&&>
{
  static void foo(){ std::cout<< "reference reference" << std::endl; }
};

int main(void)
{
  using namespace rbc::msgs;

  rbc::utils::Serializer s;
  std::array<std::uint8_t, 25> data{1,2,3,4,5,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
  web::json::value json = web::json::value::array(s.serializeSingles<std::uint8_t, 25>(data));
  std::array<std::uint8_t, 25> data2;

  rbc::utils::Deserializer::toArray<std::uint8_t, 25>(data2, json);
  assert((data2 == data));

  web::json::value j;
  j[U("this")] = web::json::value::string("that");

  auto&& [ result, new_j ] = get(j, "this");
  A<decltype(result)>::foo();
  A<decltype(new_j)>::foo();
}