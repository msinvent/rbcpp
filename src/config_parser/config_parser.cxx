//
// Created by julian on 07.11.18.
//

#include <config_parser/exceptions/config_parser_validity_exception.h>
#include <config_parser/exceptions/config_parser_init_exception.h>
#include <config_parser/exceptions/config_parser_exception.h>
#include <config_parser/config_parser.h>
#include <cpprest/ws_client.h>
#include <cpprest/json.h>
#include <fstream>

using namespace config_parser;

ConfigParser::ConfigParser(std::string filename)
  : file(filename)
{
  if (not file)
  {
    throw exception::ConfigParserInitException();
  }

  json = web::json::value::parse(file);
  if (json == web::json::value::null())
  {
    throw exception::ConfigParserException();
  }

  checkForValidity();
}

ConfigParser::~ConfigParser()
{
  if (file)
  {
    file.close();
  }
}

const ConfigParser &ConfigParser::init(std::string file)
{
  static ConfigParser config_parser(file);
  return config_parser;
}

const web::json::value &ConfigParser::get() const
{
  return json;
}

void ConfigParser::checkForValidity()
{
  try
  {
    json.at(U("config"));
    std::cout << "Checking Config file for validity" << "\n";
  }
  catch (std::exception &e)
  {
    std::cerr << "Missing key: 'config'\n";
    throw exception::ConfigParserValidityException();
  }

  auto& msg = json.at(U("config"));

  try
  {
    const auto &j = msg.at(U("pause")).as_integer();
    std::cout << "Pause rate set to " << j << " milliseconds\n";
  }
  catch (std::exception &e)
  {
    std::cerr << "Missing key: 'config/pause'\n";
    throw exception::ConfigParserValidityException();
  }

  try
  {
    const auto &j = msg.at(U("publishers")).as_integer();
    std::cout << j << " publishers configured\n";
  }
  catch (std::exception &e)
  {
    std::cerr << "Missing key: 'config/publishers'\n";
    throw exception::ConfigParserValidityException();
  }

  std::cout << "Config file valid\n";
}

int ConfigParser::pause() const
{
  int pause = json.at(U("config")).at(U("pause")).as_integer();
  return pause;
}

size_t ConfigParser::publishers() const
{
  size_t publishers = json.at(U("config")).at(U("publishers")).as_integer();
  return publishers;
}
