#include "ConverterHelper.hpp"

ConverterHelper::ConverterHelper() {}
ConverterHelper::~ConverterHelper() {}
ConverterHelper::ConverterHelper(const ConverterHelper& s) { *this = s; }
ConverterHelper& ConverterHelper::operator=(const ConverterHelper& s) {
  if (this != &s) *this = s;
  return *this;
}

bool ConverterHelper::isChar(const std::string& literal) {
  return literal.length() == 1 && !isdigit(literal[0]);
}

bool ConverterHelper::isInt(const std::string& literal) {
  if (literal.length() > 11) return false;
  char* end;
  errno = 0;
  std::strtol(literal.c_str(), &end, 10);
  return errno != ERANGE && *end == '\0';
}

bool ConverterHelper::isFloat(const std::string& literal) {
  if (*literal.rbegin() != 'f') return false;
  std::string floatPart = literal.substr(0, literal.length() - 1);
  char* end;
  std::strtod(floatPart.c_str(), &end);
  return *end == '\0';
}

bool ConverterHelper::isDouble(const std::string& literal) {
  char* end;
  std::strtod(literal.c_str(), &end);
  return *end == '\0';
}

void ConverterHelper::convertToChar(const std::string& literal) {
  char char_value = literal[0];
  int int_value = static_cast<int>(char_value);
  float float_value = static_cast<float>(int_value);
  double double_value = static_cast<double>(int_value);
  printAll(char_value, true, int_value, float_value, double_value);
}

void ConverterHelper::convertToInt(const std::string& literal) {
  char* end;
  errno = 0;
  long int_value = std::strtol(literal.c_str(), &end, 10);
  if (errno == ERANGE || *end != '\0' ||
      int_value < std::numeric_limits<int>::min() ||
      int_value > std::numeric_limits<int>::max()) {
    printImpossible();
    return;
  }
  char char_value = (int_value >= std::numeric_limits<char>::min() &&
                     int_value <= std::numeric_limits<char>::max())
                        ? static_cast<char>(int_value)
                        : -1;
  float float_value = static_cast<float>(int_value);
  double double_value = static_cast<double>(int_value);
  printAll(char_value, true, int_value, float_value, double_value);
}

void ConverterHelper::convertToFloat(const std::string& literal) {
  char* end;
  char char_value = -1;
  int valid_int = 0;
  int int_value = 0;
  errno = 0;
  std::string floatPart = literal.substr(0, literal.length() - 1);
  double double_value = std::strtod(floatPart.c_str(), &end);
  float float_value = static_cast<float>(double_value);
  if (*end != '\0' || errno == ERANGE) {
    printImpossible();
    return;
  }
  if (std::isnan(float_value) || std::isinf(float_value)) {
    double_value = static_cast<double>(float_value);
    printAll(char_value, valid_int, int_value, float_value, double_value);
    return;
  }
  if (float_value >= std::numeric_limits<char>::min() &&
      float_value <= std::numeric_limits<char>::max())
    char_value = static_cast<char>(float_value);
  if (float_value >= std::numeric_limits<int>::min() &&
      float_value <= std::numeric_limits<int>::max()) {
    valid_int = 1;
    int_value = static_cast<int>(float_value);
  }
  printAll(char_value, valid_int, int_value, float_value, double_value);
}

void ConverterHelper::convertToDouble(const std::string& literal) {
  char* end;
  char char_value = -1;
  int valid_int = 0;
  int int_value = 0;
  errno = 0;
  double double_value = std::strtod(literal.c_str(), &end);
  float float_value = static_cast<float>(double_value);

  if (*end != '\0' || errno == ERANGE) {
    printImpossible();
    return;
  }
  if (std::isnan(double_value) || std::isinf(double_value)) {
    printAll(char_value, valid_int, int_value, float_value, double_value);
    return;
  }
  if (float_value >= std::numeric_limits<char>::min() &&
      float_value <= std::numeric_limits<char>::max())
    char_value = static_cast<char>(float_value);
  if (float_value >= std::numeric_limits<int>::min() &&
      float_value <= std::numeric_limits<int>::max()) {
    valid_int = 1;
    int_value = static_cast<int>(float_value);
  }
  printAll(char_value, valid_int, int_value, float_value, double_value);
}

void ConverterHelper::printChar(char c) {
  std::cout << "char: ";
  if (isprint(c))
    std::cout << "'" << c << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
}

void ConverterHelper::printInt(int i) {
  std::cout << "int: " << i << std::endl;
}

void ConverterHelper::printFloat(float f) {
  double temp;

  std::cout << "float: ";
  if (std::isnan(f))
    std::cout << "nanf" << std::endl;
  else if (std::isinf(f))
    std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
  else if (std::modf(static_cast<double>(f), &temp) == 0.0)
    std::cout << f << ".0f" << std::endl;
  else
    std::cout << f << "f" << std::endl;
}

void ConverterHelper::printDouble(double d) {
  double temp;

  std::cout << "double: ";
  if (std::isnan(d))
    std::cout << "nan" << std::endl;
  else if (std::isinf(d))
    std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
  else if (std::modf(d, &temp) == 0.0)
    std::cout << d << ".0" << std::endl;
  else
    std::cout << d << std::endl;
}

void ConverterHelper::printAll(char char_value, bool valid_int, int int_value,
                               float float_value, double double_value) {
  if (char_value == -1)
    std::cout << "char: impossible" << std::endl;
  else
    printChar(char_value);

  if (valid_int == 0 && int_value == 0)
    std::cout << "int: impossible" << std::endl;
  else
    printInt(int_value);

  printFloat(float_value);
  printDouble(double_value);
}

void ConverterHelper::printImpossible() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}