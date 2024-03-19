#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain_ = new Brain(type_);
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain_ = new Brain(*cat.brain_);
}

Cat& Cat::operator=(const Cat &cat) {
	if (this != &cat) {
		delete this->brain_;
		this->brain_ = new Brain(*cat.brain_);
		this->type_ = cat.type_;
	}
	std::cout << "Cat operator= called" <<  std::endl;;
	return *this;
}

Cat::~Cat() {
	delete this->brain_;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "meow~ meow~" << std::endl;
}
