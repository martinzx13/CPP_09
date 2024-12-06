#pragma once

#include <iostream>
#include <map>

class BitcoinExchange {
public:
  //_______ Constructor.
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &_src);

  //_______ Overload Operator.
  BitcoinExchange &operator=(const BitcoinExchange &_src);

  //_______ Destructor.
  ~BitcoinExchange();

  void readBitcoinFile();

  void readSearchingFile();

private:
    std::map<std::string, float> bitcoinValue;
};
