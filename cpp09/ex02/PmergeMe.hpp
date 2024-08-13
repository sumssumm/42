#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <cerrno>
#include <climits>
#include <ctime>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <vector>

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe operator=(const PmergeMe &other);
  ~PmergeMe();

  void pushVector(int number);
  void sortVector();
  void mergeInsertVector(std::vector<int> &main);
  void insertVector(std::vector<int> &main, std::vector<int> &sub);
  std::vector<int>::iterator binarySearchInsertPos(std::vector<int> &vec,
                                                   int value);
  void printVector(std::vector<int> vector);

  void pushDeque(int number);
  void sortDeque();
  void mergeInsertDeque(std::deque<int> &main);
  void insertDeque(std::deque<int> &main, std::deque<int> &sub);
  std::deque<int>::iterator binarySearchInsertDeque(std::deque<int> &deq,
                                                    int value);
  void printDeque(std::deque<int> deque);

 private:
  std::vector<int> mVector;
  std::deque<int> mDeque;
};

#endif