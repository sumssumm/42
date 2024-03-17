#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hit_point_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hit_point_ = 100;
	this->energy_point_ = 50;
	this->attack_damage_ = 20;
	std::cout << "ScavTrap " << this->name_ << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap) : ClapTrap(scavtrap) {
	std::cout << "ScavTrap " << this->name_ << " copy constructor called" << std::endl;
	*this = scavtrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavtrap) {
	if (this != &scavtrap)
	{
		this->name_ = scavtrap.name_;
		this->hit_point_ = scavtrap.hit_point_;
		this->energy_point_ = scavtrap.energy_point_;
		this->attack_damage_ = scavtrap.attack_damage_;
	}
	std::cout << "ScavTrap " << this->name_ << " operator= called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name_ << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hit_point_ == 0 || this->energy_point_ == 0)
	{
		std::cout << "ScavTrap " << name_ << " can't attack anymore!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name_ 
				<< " attacks " << target
				<< ", causing " << this->attack_damage_ 
				<< " points of damage!" << std::endl;
	this->energy_point_--;
}

void ScavTrap::guardGate(void) {
	if (this->hit_point_ == 0 || this->energy_point_ == 0)
	{
		std::cout << "ScavTrap " << this->name_ << " can't guard a gate anymore!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode." << std::endl;
}
