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

  std::cout << _bitcoinData[date] << std::endl;
}