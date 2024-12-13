#include "BitcoinExchange.hpp"
#include <cstddef>
#include <exception>
#include <fstream>
#include <istream>
#include <sstream>
#include <stdexcept>
#include <string>

// _________________ Constructor.

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &_src) { *this = _src; }
BitcoinExchange::~BitcoinExchange() {}

//___________________ Overload Operator.
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &_src) {
  if (this != &_src) {
    _bitcoinData = _src._bitcoinData;
  }
  return (*this);
}

//___________________ Member Functions.

void BitcoinExchange::readBitcoinFile(const std::string &fileName) {
  std::ifstream bitFile(fileName.c_str());
  float value;
  std::string date;

  if (!bitFile.is_open())
    throw(std::runtime_error("Error Could not open the file"));

  std::cout << "File Open and ready" << std::endl;
  std::string line;
  while (std::getline(bitFile, line)) {
    std::istringstream iss(line);
    size_t position = line.find(',');
    if (position != std::string::npos) {
      date = line.substr(0, position);
      iss.str(line.substr(position + 1));
      iss >> value;
    }
    _bitcoinData[date] = value;
  }
}

void BitcoinExchange::readSearchingFile(const std::string &fileQuery) {
  std::ifstream query(fileQuery.c_str());
  if (!query.is_open())
    throw(std::runtime_error("Error could not open the file"));

  float value;
  std::string valuef;
  std::string line;
  std::string date;
  while (std::getline(query, line)) {
    std::istringstream iss(line);
    size_t position = line.find(',');
    if (position != std::string::npos) {
      date = line.substr(0, position);
      iss.str(line.substr(position + 1));
      iss >> value;
    }
      _queryData[date] = value;
  }
}

float BitcoinExchange::getPrice(const std::string &_date) {
    std::map<std::string, float>::const_iterator it = _bitcoinData.find(_date);
    if (it != _bitcoinData.end())
        return it->second;

    // If the exact date is not found, find the closest previous date
    it = _bitcoinData.lower_bound(_date);
    if (it != _bitcoinData.begin()) {
        --it;
        return it->second;
    }
    return 0;
}

void BitcoinExchange::searchValue()
{
  std::map<std::string, float>::iterator it;
  for (it = _queryData.begin(); it != _queryData.end(); it++)
  {
    float price = getPrice(it->first);
    if (price != 0)
      it->second = price;
  }
}

void BitcoinExchange::createOutputFile(const std::string &fileName, const std::map<std::string, float> &data)
{
  std::ofstream output(fileName.c_str());
  if (!output.is_open())
    throw(std::runtime_error("Error could not open the file"));

  std::map<std::string, float>::const_iterator it;
  for (it = data.begin(); it != data.end(); it++)
  {
    output << it->first << "," << it->second << std::endl;
  }
}
std::map<std::string, float> BitcoinExchange::getQueryData()
  {
    return _queryData;
  }
