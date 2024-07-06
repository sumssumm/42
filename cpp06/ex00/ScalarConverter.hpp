#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#include "ConverterHelper.hpp"

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& s);
  ScalarConverter& operator=(const ScalarConverter& s);

 public:
  static void convert(const std::string& literal);
};

#endif