#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &_src) { *this = _src; }
PmergeMe &PmergeMe::operator=(const PmergeMe &_src) {
  if (this != &_src)
    return (*this);
  return (*this);
}

//_______________ check input.

void PmergeMe::inputCheck(const std::string &val) {

  std::cout << val << std::endl;
  int value;
  char *end;

  value = std::strtol(val.c_str(), &end, 10);
  if (*end != '\0')
    throw(std::runtime_error("Error not valid number"));
  _sortVector.push_back(value);
  _sortList.push_back(value);
}

void PmergeMe::initialPairingVector() {
  for (size_t i = 0; i < _sortVector.size(); i++)
    if (_sortVector[i] > _sortVector[i + 1])
      std::swap(_sortVector[i], _sortVector[i + 1]);
}

void PmergeMe::initialPairingList() {
  for (std::list<int>::iterator it = _sortList.begin();
       std::next(it) != _sortList.end(); std::advance(it, 2))
    if (*it > *std::next(it))
      std::iter_swap(it, std::next(it));
}

std::list<int> PmergeMe::getList() { return (_sortList); }

std::vector<int> PmergeMe::getVector() { return (_sortVector); }