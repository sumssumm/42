#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void check_leak() { system("leaks animal"); }

int main() {
  // atexit(check_leak);
  // Animal a; // 인스턴스화 불가능
  // const Animal* meta = new Animal();
  const Animal *j = new Dog();
  std::cout << std::endl;
  const Animal *i = new Cat();
  std::cout << std::endl;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  j->makeSound();
  i->makeSound();
  std::cout << std::endl;

  delete i;
  delete j;

  return 0;
}