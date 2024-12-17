#include "PmergeMe.hpp"
#include <exception>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Not enought args" << std::endl;
    return (1);
  }

  PmergeMe sorting;
  try {

    for (int i = 1; i < argc; i++)
      sorting.inputCheck(argv[i]);
    
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}