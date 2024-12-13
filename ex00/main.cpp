#include "BitcoinExchange.hpp"

int main(int arg, char *argv[])
{
    //1. Check the number of arguments.
    if (arg == 1)
        return 1;

    BitcoinExchange bitConvert;

    bitConvert.readBitcoinFile("data.csv");
    //2. Check the open file function.
    std::cout << "// ______________ Before Output File ______________" << std::endl;
    std::ifstream file1(argv[1]);
    std::string line1;
    while(std::getline(file1, line1))
        std::cout << line1 << std::endl;

    bitConvert.readSearchingFile(argv[1]);
    bitConvert.searchValue();
    bitConvert.createOutputFile("argv[1]", bitConvert.getQueryData());

    std::cout << "// ______________ After Output File ______________" << std::endl;
    std::ifstream file("argv[1]");
    std::string line;
    while(std::getline(file, line))
        std::cout << line << std::endl;
}