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

  std::cout << "Original char array: ";
  iter(charArray, charArrayLength, printElement<char>);
  std::cout << std::endl;

  iter(charArray, charArrayLength, incrementElement<char>);
  std::cout << "Incremented char array: ";
  iter(charArray, charArrayLength, printElement<char>);

  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  double doubleArray[] = {1.1, 1.2, 1.3};
  std::cout << "Original double array: ";
  iter(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]),
       printElement<double>);
  std::cout << std::endl;

  iter(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]),
       incrementElement<double>);

  std::cout << "Incremented double array: ";
  iter(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]),
       printElement<double>);

  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  const std::string strArray[] = {"hello", "world", "!"};
  size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

  std::cout << "const string array: ";
  iter(strArray, strArrayLength, printElement<std::string>);
  std::cout << std::endl;
  std::cout << "-------------------------------------" << std::endl;

  const int arr[] = {1, 2, 3};
  std::cout << "const int arr: ";
  iter(arr, 3, printElement<int>);
  std::cout << std::endl;

  // iter(arr, 3, incrementElement<int>); // 오류: const 배열의 요소를 수정할 수
  // 없음

  return 0;
}