#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdexcept>

class RPN {
 public:
  RPN(char* argv);
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();

 private:
  std::stack<int> stack;
  std::string numStr;

  RPN();
}

#endif