//
// Created by Julian on 13.10.18.
//

#include <test/csv_reader.h>

using namespace test;
using std::string;
using std::vector;

CSVReader::CSVReader(const string filename, string delim)
  : file(std::ifstream(filename)), delimiter(delim)
{
  if (file)
  {
    data.reserve(100);
  } else
  {
    std::cerr << "Can't open file " << filename << ". Exiting.\n";
  }
  processFile();
}

CSVReader::~CSVReader()
{
  if (file)
    file.close();
}

const std::unordered_map<string, vector<string>>& CSVReader::getData() const
{
  return data;
}

void CSVReader::saveVec(const vector<string> &line) {
  const auto &msg_class = line[0];
  const auto &result = line[1];

  if (data.find(msg_class) != end(data))
  {
    data.at(msg_class).push_back(std::move(result));
  } else {
    data[msg_class].reserve(2);
    data.at(msg_class).push_back(std::move(result));
  }
}

void CSVReader::processFile() {
  string line;
  size_t line_counter = 0;
  using namespace boost::algorithm;

  while (getline(file, line)) {
    ++line_counter;
    vector<string> vec;
    split(vec, line, boost::is_any_of(delimiter));
    if (line_counter == 1)
      continue;

    saveVec(vec);
  }
}