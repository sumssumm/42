#include <cstdlib>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char **) {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }

  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }
  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror;

  std::cout << "--------------------------------" << std::endl;
  // 기본 생성자로 빈 배열 생성
  Array<int> emptyArray;
  std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;
  try {
    std::cout << emptyArray[0] << std::endl; // 예외 발생
  } catch (const std::exception &e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // n개의 요소로 초기화된 배열 생성
  unsigned int n = 5;
  Array<int> intArray(n);
  for (unsigned int i = 0; i < n; i++)
    std::cout << intArray[i] << "\n";
  std::cout << "Size of intArray: " << intArray.size() << std::endl;
  for (unsigned int i = 0; i < intArray.size(); ++i) {
    intArray[i] = i * 2;
  }
  std::cout << std::endl;

  for (unsigned int i = 0; i < intArray.size(); ++i) {
    std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
  }
  std::cout << std::endl;

  // 복사 생성자 테스트
  Array<int> copyArray(intArray);
  std::cout << "Size of copyArray: " << copyArray.size() << std::endl;
  for (unsigned int i = 0; i < copyArray.size(); ++i) {
    std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
  }
  std::cout << std::endl;

  // 할당 연산자 테스트
  Array<int> assignedArray;
  assignedArray = intArray;
  std::cout << "Size of assignedArray: " << assignedArray.size() << std::endl;
  for (unsigned int i = 0; i < assignedArray.size(); ++i) {
    std::cout << "assignedArray[" << i << "] = " << assignedArray[i]
              << std::endl;
  }
  std::cout << std::endl;

  // 복사본 수정 후 원본 확인
  copyArray[0] = 100;
  std::cout << "After modifying copyArray, intArray[0]: " << intArray[0]
            << std::endl;

  // 원본 수정 후 복사본 확인
  intArray[1] = 200;
  std::cout << "After modifying intArray, copyArray[1]: " << copyArray[1]
            << std::endl;

  // 할당된 배열 수정 후 원본 확인
  assignedArray[2] = 300;
  std::cout << "After modifying assignedArray, intArray[2]: " << intArray[2]
            << std::endl;
  std::cout << std::endl;

  // 인덱스 범위 초과 테스트
  try {
    intArray[10] = 42; // 범위를 벗어난 인덱스
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  std::cout << std::endl;

  // char 타입 테스트
  unsigned int charSize = 5;
  Array<char> charArray(charSize);
  std::cout << "Size of charArray: " << charArray.size() << std::endl;
  for (unsigned int i = 0; i < charArray.size(); ++i) {
    charArray[i] = 'a' + i;
  }
  for (unsigned int i = 0; i < charArray.size(); ++i) {
    std::cout << "charArray[" << i << "] = " << charArray[i] << std::endl;
  }
  std::cout << std::endl;

  // std::string 타입 테스트
  unsigned int stringSize = 3;
  Array<std::string> stringArray(stringSize);
  std::cout << "Size of stringArray: " << stringArray.size() << std::endl;
  stringArray[0] = "Hello";
  stringArray[1] = "World";
  stringArray[2] = "!";
  for (unsigned int i = 0; i < stringArray.size(); ++i) {
    std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
  }
  std::cout << std::endl;

  // const 타입 테스트
  const Array<std::string> constStringArray = stringArray;
  std::cout << "Size of constStringArray: " << constStringArray.size()
            << std::endl;
  for (unsigned int i = 0; i < constStringArray.size(); ++i) {
    std::cout << "constStringArray[" << i << "] = " << constStringArray[i]
              << std::endl;
  }
  std::cout << std::endl;

  // const 배열에 접근 및 수정 시도
  // constStringArray[0] = "Modified";  // 컴파일 오류 발생

  // 복사 생성자 테스트
  Array<std::string> copyStringArray(stringArray);
  std::cout << "Size of copyStringArray: " << copyStringArray.size()
            << std::endl;
  for (unsigned int i = 0; i < copyStringArray.size(); ++i) {
    std::cout << "copyStringArray[" << i << "] = " << copyStringArray[i]
              << std::endl;
  }
  std::cout << std::endl;

  // 할당 연산자 테스트
  Array<std::string> assignedStringArray;
  assignedStringArray = stringArray;
  std::cout << "Size of assignedStringArray: " << assignedStringArray.size()
            << std::endl;
  for (unsigned int i = 0; i < assignedStringArray.size(); ++i) {
    std::cout << "assignedStringArray[" << i << "] = " << assignedStringArray[i]
              << std::endl;
  }
  std::cout << std::endl;

  // 복사본 수정 후 원본 확인
  copyStringArray[0] = "Modified";
  std::cout << "After modifying copyStringArray, stringArray[0]: "
            << stringArray[0] << std::endl;

  // 원본 수정 후 복사본 확인
  stringArray[1] = "Changed";
  std::cout << "After modifying stringArray, copyStringArray[1]: "
            << copyStringArray[1] << std::endl;

  // 할당된 배열 수정 후 원본 확인
  assignedStringArray[2] = "Different";
  std::cout << "After modifying assignedStringArray, stringArray[2]: "
            << stringArray[2] << std::endl;
  std::cout << std::endl;

  return 0;
}