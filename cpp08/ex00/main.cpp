#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);

  try {
    std::vector<int>::iterator it = easyfind(vec, 3);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::vector<int>::iterator it = easyfind(vec, 42);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(40);
  lst.push_back(50);

  try {
    std::list<int>::iterator it = easyfind(lst, 50);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    std::list<int>::iterator it = easyfind(lst, 42);
    std::cout << "Value found: " << *it << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}