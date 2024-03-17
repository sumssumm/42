#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hit_point_ = 100;
	this->energy_point_ = 100;
	this->attack_damage_ = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_point_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 30;
	std::cout << "FragTrap " << this->name_ << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragtrap) : ClapTrap(fragtrap) {
	std::cout << "FragTrap " << this->name_ << " copy constructor called" << std::endl;
	*this = fragtrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap) {
	if (this != &fragtrap)
	{
		this->name_ = fragtrap.name_;
		this->hit_point_ = fragtrap.hit_point_;
		this->energy_point_ = fragtrap.energy_point_;
		this->attack_damage_ = fragtrap.attack_damage_;
	}
	std::cout << "FragTrap " << this->name_ << " operator= called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name_ << " destructor called" << std::endl;
}

void FragTrap::highFiveGuys(void) {
	if (this->hit_point_ == 0 || this->energy_point_ == 0)
	{
		std::cout << "FragTrap " << this->name_ << " can't request a high five anymore!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name_ << " requests a high five." << std::endl;
}
