#include <iostream>
#include <list>

#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << "top: " << mstack.top() << std::endl;
  std::cout << "---------------------------------" << std::endl;

  mstack.pop();

  std::cout << "top: " << mstack.top() << std::endl;
  std::cout << "---------------------------------" << std::endl;

  std::cout << "size: " << mstack.size() << std::endl;
  std::cout << "---------------------------------" << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  std::cout << "Stack elements:" << std::endl;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::cout << "---------------------------------" << std::endl;

  std::cout << "Reverse stack elements:" << std::endl;
  for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
       rit != mstack.rend(); ++rit) {
    std::cout << *rit << std::endl;
  }
  std::cout << "---------------------------------" << std::endl;

  std::stack<int> s(mstack);
  std::cout << "Stack elements:" << std::endl;
  while (!s.empty()) {
    std::cout << s.top() << std::endl;
    s.pop();
  }
  std::cout << "---------------------------------" << std::endl;

  std::list<int> mlist;

  mlist.push_back(5);
  mlist.push_back(17);

  std::cout << "top: " << mlist.back() << std::endl;
  std::cout << "---------------------------------" << std::endl;

  mlist.pop_back();

  std::cout << "top: " << mlist.back() << std::endl;
  std::cout << "size: " << mlist.size() << std::endl;
  std::cout << "---------------------------------" << std::endl;

  mlist.push_back(3);
  mlist.push_back(5);
  mlist.push_back(737);
  mlist.push_back(0);

  std::list<int>::iterator lit = mlist.begin();
  std::list<int>::iterator lite = mlist.end();

  ++lit;
  --lit;
  std::cout << "List elements:" << std::endl;
  while (lit != lite) {
    std::cout << *lit << std::endl;
    ++lit;
  }
  std::cout << "---------------------------------" << std::endl;

  std::cout << "Reverse list elements:" << std::endl;
  for (std::list<int>::reverse_iterator lrit = mlist.rbegin();
       lrit != mlist.rend(); ++lrit) {
    std::cout << *lrit << std::endl;
  }
  std::cout << "---------------------------------" << std::endl;

  return 0;
}