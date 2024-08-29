#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  // Animal a;
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