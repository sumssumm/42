#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <limits>

class RPN {
 public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  double runCalculate(const std::string &expression);

 private:
  std::stack<double> stack;

  void checkNumber(double number) const;
  void checkOperator(const std::string &token) const;
};

#endif