#include "function.hpp"
#include "iter.hpp"

int main() {
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Original int array: ";
  iter(intArray, intArrayLength, printElement<int>);
  std::cout << std::endl;

  iter(intArray, intArrayLength, incrementElement<int>);

  std::cout << "Incremented int array: ";
  iter(intArray, intArrayLength, printElement<int>);
  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  char charArray[] = {'a', 'b', 'c'};
  size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

  std::cout << "Original string array: ";
  iter(charArray, charArrayLength, printElement<char>);
  std::cout << std::endl;

  iter(charArray, charArrayLength, incrementElement<char>);
  std::cout << "Incremented int array: ";
  iter(charArray, charArrayLength, printElement<char>);

  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  const std::string strArray[] = {"hello", "world", "!"};
  size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

  std::cout << "Original string array: ";
  iter(strArray, strArrayLength, printElement<std::string>);
  std::cout << std::endl;

  return 0;
}