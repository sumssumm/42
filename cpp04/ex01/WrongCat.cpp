#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type_ = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = cat;
}

WrongCat& WrongCat::operator=(const WrongCat &cat){
	if (this != &cat)
		this->type_ = cat.type_;
	std::cout << "WrongCat operator= called";
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "meow~ meow~" << std::endl;
}

