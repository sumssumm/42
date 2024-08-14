#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : stack(other.stack) {}

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    this->stack = other.stack;
  }
  return *this;
}

RPN::~RPN() {}

double RPN::runCalculate(const std::string &expression) {
  std::stringstream ss(expression);
  std::string token;

  while (ss >> token) {
    if (token.size() == 1 && isdigit(token[0])) {
      double number = token[0] - '0';
      checkNumber(number);
      stack.push(number);
    } else {
      checkOperator(token);
      if (stack.size() < 2)
        throw std::runtime_error("Error: not enough number");

      double b = stack.top();
      stack.pop();
      double a = stack.top();
      double cal = 0.0;
      stack.pop();
      if (token == "+")
        cal = a + b;
      else if (token == "-")
        cal = a - b;
      else if (token == "*")
        cal = a * b;
      else if (token == "/") {
        if (b == 0) throw std::runtime_error("Error: divide by 0");
        cal = a / b;
      }

      // if (token == "+")
      //   stack.push(a + b);
      // else if (token == "-")
      //   stack.push(a - b);
      // else if (token == "*")
      //   stack.push(a * b);
      // else if (token == "/") {
      //   if (b == 0) throw std::runtime_error("Error: divide by 0");
      //   stack.push(a / b);

      if (cal > std::numeric_limits<long>::max() ||
          cal < std::numeric_limits<long>::min()) {
        throw std::runtime_error("Error: number is greater than long max");
      }
      stack.push(cal);
    }
  }

  if (stack.size() != 1) throw std::runtime_error("Error: invalid expression");
  if (stack.top() > std::numeric_limits<long>::max())
    throw std::runtime_error("Error: number is greater than long max");
  return stack.top();
}

void RPN::checkNumber(double number) const {
  if (number >= 10)
    throw std::runtime_error("Error: number is greater than or equal to 10");
}

void RPN::checkOperator(const std::string &token) const {
  if (token != "+" && token != "-" && token != "*" && token != "/")
    throw std::runtime_error("Error");
}