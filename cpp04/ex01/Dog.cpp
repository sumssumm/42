#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
  this->brain_ = new Brain(type_);
}

Dog::Dog(const Dog &dog) : Animal(dog) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->brain_ = new Brain(*dog.brain_);
}

Dog &Dog::operator=(const Dog &dog) {
  std::cout << "Dog operator= called" << std::endl;

  if (this != &dog) {
    delete this->brain_;
    this->brain_ = new Brain(*dog.brain_);
    this->type_ = dog.type_;
    std::cout << "this brain ptr :\t" << this->brain_ << std::endl;
    std::cout << "other brain ptr :\t" << dog.brain_ << std::endl;
  }
  return *this;
}

Dog::~Dog() {
  delete this->brain_;
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const { std::cout << "woof~ woof~" << std::endl; }
