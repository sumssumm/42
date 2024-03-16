#include "Fixed.hpp"

const int Fixed::bits_ = 8;

Fixed::Fixed() : number_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number) : number_(number << bits_) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : number_(roundf(number * (1 << bits_))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->number_ = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->number_) / (1 << this->bits_);
}

int	Fixed::toInt(void) const {
	return this->number_ >> this->bits_;
}

int	Fixed::getRawBits(void) const {
	return this->number_;
}
void	Fixed::setRawBits(int const raw) {
	this->number_ = raw;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}