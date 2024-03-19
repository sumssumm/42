#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type_ = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog &dog){
	if (this != &dog)
		this->type_ = dog.type_;
	std::cout << "Dog operator= called" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "woof~ woof~" << std::endl;
}
