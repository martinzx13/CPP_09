#include "PmergeMe.hpp"
#include <exception>

template <typename T> void print(const T &container) {
  std::cout << "[";
  for (typename T::const_iterator it = container.begin(); it != container.end();
       ++it) {
    typename T::const_iterator itCheck = it;
    std::cout << *it;
    if (++itCheck != container.end())
      std::cout << ",";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Not enought args" << std::endl;
    return (1);
  }

  PmergeMe sorting;
  try {

    for (int i = 1; i < argc; i++)
      sorting.inputCheck(argv[i]);

    std::cout << "::::::::::: STEP 1 PAIR SORT " << std::endl;
    std::cout << YELLOW << "___________ Print List ____________" << std::endl;
    print(sorting.getList());
    std::cout << YELLOW << "___________ Print Swap ____________" << std::endl;
    sorting.initialPairingList();
    print(sorting.getList());
    std::cout << MAGENTA << "___________ Print Vector ____________"
              << std::endl;
    print(sorting.getVector());
    std::cout << YELLOW << "___________ Print Swap Vector ____________"
              << std::endl;
    sorting.initialPairingVector();
    print(sorting.getVector());

    std::cout << "::::::::::: STEP 3. Recursive Merging " << std::endl;
    sorting.runTimeManager();
    print(sorting.getVector());

    print(sorting.getList());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}