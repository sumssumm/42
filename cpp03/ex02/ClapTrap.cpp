#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name_("default"), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_point_(10), energy_point_(10), attack_damage_(0) {
	std::cout << "ClapTrap " << name_ << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "ClapTrap " << name_ << " copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &claptrap) {
	std::cout << "ClapTrap " << name_ << " operator= called" << std::endl;
	if (this != &claptrap)
	{
		name_ = claptrap.name_;
		hit_point_ = claptrap.hit_point_;
		energy_point_ = claptrap.energy_point_;
		attack_damage_ = claptrap.attack_damage_;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name_ << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (hit_point_ == 0 || energy_point_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " can't attack anymore!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name_ 
				<< " attacks " << target
				<< ", causing " << attack_damage_ 
				<< " points of damage!" << std::endl;
	energy_point_--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (hit_point_ < amount)
		hit_point_ = 0;
	else
		hit_point_ -= amount;
	if (hit_point_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " is dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name_ 
				<< " takes "  << amount
				<< " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_point_ == 0 || energy_point_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " can't repair anymore!" << std::endl;
		return ;
	}
	energy_point_--;
	hit_point_ += amount;
	std::cout << "ClapTrap " << name_
			  << " is repaired " << amount
			  << " hit points!" << std::endl;
}
