#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  j->makeSound();
  i->makeSound();
  meta->makeSound();
  std::cout << "-------------------------" << std::endl;

  const WrongAnimal *w_animal = new WrongAnimal();
  const WrongAnimal *w_cat = new WrongCat();

  std::cout << w_animal->getType() << " " << std::endl;
  std::cout << w_cat->getType() << " " << std::endl;
  w_animal->makeSound();
  w_cat->makeSound();
  std::cout << "-------------------------" << std::endl;

  delete meta;
  delete j;
  delete i;
  std::cout << std::endl;
  delete w_cat;
  delete w_animal;

  return 0;
}