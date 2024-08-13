#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe() {}

/* vector */

std::vector<int> generateJacobsthalVec(int size) {
  std::vector<int> jacobsthal;
  jacobsthal.push_back(1);
  if (size > 1) {
    jacobsthal.push_back(3);
    for (int i = 2;; i++) {
      int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
      jacobsthal.push_back(next);
      if (next >= size) break;
    }
  }
  return jacobsthal;
}

void PmergeMe::pushVector(int number) { mVector.push_back(number); }

void PmergeMe::sortVector() {
  std::cout << "Before: ";
  printVector(mVector);

  mergeInsertVector(mVector);

  std::cout << "After: ";
  printVector(mVector);
  std::cout << mVector.size() << std::endl;
  if (std::is_sorted(mVector.begin(), mVector.end())) {
    std::cout << "Sorted!" << std::endl;
  }
}

void PmergeMe::mergeInsertVector(std::vector<int> &main) {
  std::vector<int> main_chain;
  std::vector<int> pending_chain;

  if (main.size() < 2) return;

  for (size_t i = 0; i < main.size() / 2; ++i) {
    main_chain.push_back(std::max(main[i * 2], main[i * 2 + 1]));
    pending_chain.push_back(std::min(main[i * 2], main[i * 2 + 1]));
  }

  if (main.size() % 2 != 0) pending_chain.push_back(main.back());

  mergeInsertVector(main_chain);
  insertVector(main_chain, pending_chain);
  main = main_chain;
}

void PmergeMe::insertVector(std::vector<int> &main, std::vector<int> &sub) {
  std::vector<int> jacobsthal = generateJacobsthalVec(sub.size());

  // 야콥스탈 수열에 따라 순서대로 삽입
  int prevIdx = 1;
  main.insert(binarySearchInsertPos(main, sub[0]), sub[0]);
  for (size_t i = 1; i < jacobsthal.size(); ++i) {
    size_t index =
        (jacobsthal[i] >= sub.size() ? sub.size() : jacobsthal[i]) - 1;

    for (int j = index; j >= prevIdx; --j) {
      int value = sub[j];
      std::vector<int>::iterator insert_pos =
          binarySearchInsertPos(main, value);
      main.insert(insert_pos, value);
    }
    prevIdx = index + 1;
  }
}

std::vector<int>::iterator PmergeMe::binarySearchInsertPos(
    std::vector<int> &vec, int value) {
  size_t low = 0;
  size_t high = vec.size();

  while (low < high) {
    size_t mid = low + (high - low) / 2;
    if (vec[mid] < value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return vec.begin() + low;
}

void PmergeMe::printVector(std::vector<int> vector) {
  for (std::vector<int>::iterator it = vector.begin(); it != vector.end();
       it++) {
    std::cout << *it;
    if (it != vector.end() - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

/* deque */

std::deque<int> generateJacobsthalDeq(int size) {
  std::deque<int> jacobsthal;
  jacobsthal.push_back(1);
  if (size > 1) {
    jacobsthal.push_back(3);
    for (int i = 2;; i++) {
      int next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
      jacobsthal.push_back(next);
      if (next >= size) break;
    }
  }
  return jacobsthal;
}

void PmergeMe::pushDeque(int number) { mDeque.push_back(number); }

void PmergeMe::sortDeque() {
  // std::cout << "Before: ";
  // printDeque(mDeque);

  mergeInsertDeque(mDeque);

  // std::cout << "After: ";
  // printDeque(mDeque);
  if (std::is_sorted(mDeque.begin(), mDeque.end())) {
    std::cout << "Sorted!" << std::endl;
  }
}

void PmergeMe::mergeInsertDeque(std::deque<int> &main) {
  std::deque<int> main_chain;
  std::deque<int> pending_chain;

  if (main.size() < 2) return;

  for (size_t i = 0; i < main.size() / 2; ++i) {
    main_chain.push_back(std::max(main[i * 2], main[i * 2 + 1]));
    pending_chain.push_back(std::min(main[i * 2], main[i * 2 + 1]));
  }

  if (main.size() % 2 != 0) pending_chain.push_back(main.back());

  mergeInsertDeque(main_chain);
  insertDeque(main_chain, pending_chain);
  main = main_chain;
}

void PmergeMe::insertDeque(std::deque<int> &main, std::deque<int> &sub) {
  std::deque<int> jacobsthal = generateJacobsthalDeq(sub.size());

  // 야콥스탈 수열에 따라 순서대로 삽입
  int prevIdx = 1;
  main.insert(binarySearchInsertDeque(main, sub[0]), sub[0]);
  for (size_t i = 1; i < jacobsthal.size(); ++i) {
    size_t index =
        (jacobsthal[i] >= sub.size() ? sub.size() : jacobsthal[i]) - 1;

    for (int j = index; j >= prevIdx; --j) {
      int value = sub[j];
      std::deque<int>::iterator insert_pos =
          binarySearchInsertDeque(main, value);
      main.insert(insert_pos, value);
    }
    prevIdx = index + 1;
  }
}

std::deque<int>::iterator PmergeMe::binarySearchInsertDeque(
    std::deque<int> &deq, int value) {
  size_t low = 0;
  size_t high = deq.size();

  while (low < high) {
    size_t mid = low + (high - low) / 2;
    if (deq[mid] < value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return deq.begin() + low;
}

void PmergeMe::printDeque(std::deque<int> deque) {
  for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++) {
    std::cout << *it;
    if (it != deque.end() - 1) std::cout << " ";
  }
  std::cout << std::endl;
}
