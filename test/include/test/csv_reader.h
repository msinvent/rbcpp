//
// Created by Julian on 13.10.18.
//

#ifndef ROSBRIDGECLIENT_CSV_READER_H
#define ROSBRIDGECLIENT_CSV_READER_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <boost/algorithm/string.hpp>

namespace test
{

class CSVReader
{
public:
  CSVReader() = delete;
  CSVReader(const std::string filename, std::string delim = ",");
  ~CSVReader();
  const std::unordered_map<std::string, std::vector<std::string>> &getData() const;

private:
  void saveVec(const std::vector<std::string> &line);
  void processFile();

  std::unordered_map<std::string, std::vector<std::string>> data;
  std::ifstream file;
  std::string delimiter;
};
} // namespace test

#endif //ROSBRIDGECLIENT_CSV_READER_H
