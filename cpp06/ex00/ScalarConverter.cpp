#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& s) { *this = s; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s) {
  if (this != &s) *this = s;
  return *this;
}

void ScalarConverter::convert(const std::string& literal) {
  if (ConverterHelper::isChar(literal)) {
    ConverterHelper::convertToChar(literal);
  } else if (ConverterHelper::isInt(literal)) {
    ConverterHelper::convertToInt(literal);
  } else if (ConverterHelper::isFloat(literal)) {
    ConverterHelper::convertToFloat(literal);
  } else if (ConverterHelper::isDouble(literal)) {
    ConverterHelper::convertToDouble(literal);
  } else {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
  }
}