#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = animal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
  if (this != &animal)
    this->type_ = animal.type_;
  std::cout << "WrongAnimal operator= called";
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal sound???" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type_; }