#include "AMateria.hpp"

// Constructors
AMateria::AMateria() : type_("default") {
	// std::cout << "\e[0;33mDefault Constructor called of AMateria\e[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) : type_(type) {
}

AMateria::AMateria(const AMateria &copy) : type_(copy.type_) {
	(void) copy;
	// std::cout << "\e[0;33mCopy Constructor called of AMateria\e[0m" << std::endl;
}

// Destructor
AMateria::~AMateria() {
	// std::cout << "\e[0;31mDestructor called of AMateria\e[0m" << std::endl;
}

// Operators
AMateria & AMateria::operator=(const AMateria &assign) {
	(void) assign;
	return *this;
}

std::string const & AMateria::getType() const {
	return this->type_;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}