#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN {
public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  int runCalculate(const std::string &expression);

private:
  std::stack<int> stack;

  void checkNumber(int number) const;
  void checkOperator(const std::string &token) const;
};

#endif