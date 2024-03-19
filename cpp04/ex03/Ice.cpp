#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice")
{
	// std::cout << "\e[0;33mDefault Constructor called of Ice\e[0m" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	// std::cout << "\e[0;33mCopy Constructor called of Ice\e[0m" << std::endl;
}

// Destructor
Ice::~Ice()
{
	// std::cout << "\e[0;31mDestructor called of Ice\e[0m" << std::endl;
}

// Operators
Ice & Ice::operator=(const Ice &assign)
{
	if (this != &assign)
	{
		this->AMateria::operator=(assign);
		this->type_ = assign.type_;
	}
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}


void Ice::use(ICharacter& target) {
	std::cout << "* shoots an Ice bolt at " << target.getName() << " *" << std::endl;
}