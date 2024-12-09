#include "BitcoinExchange.hpp"

int main(int arg, char *argv[])
{
    //1. Check the number of arguments.
    if (arg == 1)
        return 1;

    BitcoinExchange bitConvert;

    bitConvert.readBitcoinFile(argv[1]);
    //2. Check the open file function.
}