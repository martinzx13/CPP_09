#pragma once

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange {
public:
  //_______ Constructor.
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &_src);

  //_______ Overload Operator.
  BitcoinExchange &operator=(const BitcoinExchange &_src);

  //_______ Destructor.
  ~BitcoinExchange();

  //_______ Member Functions.

  //_______ Read File
  void readBitcoinFile(const std::string &fileName);

  void readSearchingFile();

private:
    std::map<std::string, float> _bitcoinData;
};
