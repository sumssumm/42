#ifndef CONVERTERHELPER_HPP
#define CONVERTERHELPER_HPP

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

class ConverterHelper {
private:
  ConverterHelper();
  ~ConverterHelper();
  ConverterHelper(const ConverterHelper &s);
  ConverterHelper &operator=(const ConverterHelper &s);

  static void printAll(char char_value, bool valid_int, int int_value,
                       float float_value, double double_value);

public:
  static bool isChar(const std::string &literal);
  static bool isInt(const std::string &literal);
  static bool isFloat(const std::string &literal);
  static bool isDouble(const std::string &literal);

  static void convertToChar(const std::string &literal);
  static void convertToInt(const std::string &literal);
  static void convertToFloat(const std::string &literal);
  static void convertToDouble(const std::string &literal);

  static void printChar(char c);
  static void printInt(int i);
  static void printFloat(float f);
  static void printDouble(double d);
  static void printImpossible();
};

#endif