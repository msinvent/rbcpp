//
// Created by julian on 07.11.18.
//

#include <config_parser/config_parser.h>
#include <config_parser/exceptions/config_parser_init_exception.h>
#include <config_parser/exceptions/config_parser_exception.h>
#include <fstream>
#include <cpprest/json.h>

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
