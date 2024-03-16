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
	return static_cast<float>(number_) / (1 << bits_);
}

int	Fixed::toInt(void) const {
	return number_ >> bits_;
}

/* comparison operators */
bool	Fixed::operator>(const Fixed &fixed) const {
	return getRawBits() > fixed.getRawBits();
}

bool	Fixed::operator<(const Fixed &fixed) const {
	return getRawBits() < fixed.getRawBits();
}

bool	Fixed::operator>=(const Fixed &fixed) const {
	return getRawBits() >= fixed.getRawBits();
}

bool	Fixed::operator<=(const Fixed &fixed) const {
	return getRawBits() <= fixed.getRawBits();
}

bool	Fixed::operator==(const Fixed &fixed) const {
	return getRawBits() == fixed.getRawBits();
}

bool	Fixed::operator!=(const Fixed &fixed) const {
	return getRawBits() != fixed.getRawBits();
}

/* arithmetic operators */
Fixed	Fixed::operator+(const Fixed &fixed) const {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed) const {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed) const {
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed) const {
	return Fixed(toFloat() / fixed.toFloat());
}

/* increment/decrement operators */
Fixed&	Fixed::operator++(void) {
	this->number_++;
	return *this;
}

const Fixed Fixed::operator++(int) {
	Fixed	tmp(*this);

	this->number_++;
	return tmp;
}

Fixed&	Fixed::operator--(void) {
	this->number_--;
	return *this;
}

const Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	this->number_--;
	return tmp;
}

/* min & max */
Fixed&	Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 > fixed2)
		return fixed2;
	return fixed1;
}

const Fixed	Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if (fixed1 > fixed2)
		return fixed2;
	return fixed1;
}

Fixed&	Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

const Fixed	Fixed::max(Fixed const &fixed1, Fixed const &fixed2) {
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
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