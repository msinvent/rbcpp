//
// Created by julian on 07.11.18.
//

#ifndef ROSBRIDGECLIENT_CONFIG_PARSER_H
#define ROSBRIDGECLIENT_CONFIG_PARSER_H

#include <string>
#include <memory>
#include <fstream>
#include <cpprest/json.h>

namespace config_parser
{

class ConfigParser
{
public:
  static const ConfigParser &init(std::string file);

  ~ConfigParser();

  const web::json::value &get() const;

  int pause() const;

  int publishers() const;

  std::string host() const;

private:
  ConfigParser() = delete;

  explicit ConfigParser(std::string filename);

  void checkForValidity();

  std::ifstream file;
  web::json::value json;
};

} // namespace config_parser

#endif //ROSBRIDGECLIENT_CONFIG_PARSER_H
