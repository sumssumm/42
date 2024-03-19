#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->brain_ = new Brain(type_);
}

Cat::Cat(const Cat &cat) : Animal(cat) {
	std::cout << "Cat copy constructor called" << std::endl;
<<<<<<< HEAD
	this->brain_ = new Brain(*cat.brain_);
}

Cat& Cat::operator=(const Cat &cat) {
	if (this != &cat) {
		delete this->brain_;
		this->brain_ = new Brain(*cat.brain_);
=======
	*this = cat;
}

Cat& Cat::operator=(const Cat &cat) {
	if (this != &cat)
	{

	}
>>>>>>> d55bb18d4372955eb4e45d1e3454b7af7679b025
		this->type_ = cat.type_;
	}
	std::cout << "Cat operator= called" <<  std::endl;;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	if (this->brain_) //check
		delete this->brain_;
}

void Cat::makeSound() const {
	std::cout << "meow~ meow~" << std::endl;
}
