#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
  if (this != &animal)
    this->type_ = animal.type_;
  std::cout << "Animal operator= called" << std::endl;
  return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

void Animal::makeSound() const { std::cout << "Animal sound!!!" << std::endl; }
std::string Animal::getType() const { return this->type_; }