#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe {

public:
  PmergeMe();
  PmergeMe(const PmergeMe &_src);
  PmergeMe &operator=(const PmergeMe &_src);
  ~PmergeMe();

  // ______________________ Check the input.
  void inputCheck(const std::string &val);
  void initialPairingList();
  void initialPairingVector();
  std::list<int> getList();
  std::vector<int> getVector();

private:
  std::vector<int> _sortVector;
  std::list<int> _sortList;
};