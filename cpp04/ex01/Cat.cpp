#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type_ = "Cat";
	this->brain_ = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain_ = new Brain(*cat.brain_);
	*this = cat;
}

Cat& Cat::operator=(const Cat &cat) {
	if (this != &cat)
	{
		delete this->brain_;
	}
		this->type_ = cat.type_;
	std::cout << "Cat operator= called";
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain_;
}

void Cat::makeSound() const {
	std::cout << "meow~ meow~" << std::endl;
}
