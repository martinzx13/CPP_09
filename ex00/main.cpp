#include "BitcoinExchange.hpp"

int main(int arg, char *argv[])
{
    //1. Check the number of arguments.
    if (arg == 1)
        return 1;

    BitcoinExchange bitConvert;

    bitConvert.readBitcoinFile("data.csv");
    //2. Check the open file function.
    bitConvert.readSearchingFile(argv[1]);
    
}