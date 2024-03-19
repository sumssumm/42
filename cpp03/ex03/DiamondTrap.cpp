#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	this->name_ = "default";
	ClapTrap::name_ += "_clap_name";
	this->hit_point_ = FragTrap::hit_point_; //100
	this->energy_point_ = ScavTrap::energy_point_; //50
	this->attack_damage_ = FragTrap::attack_damage_; //30
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name_(name) {
	ClapTrap::name_ += "_clap_name";
	this->hit_point_ = FragTrap::hit_point_;
	this->energy_point_ = ScavTrap::energy_point_;
	this->attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << this->name_ << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap) : ClapTrap(trap), FragTrap(trap), ScavTrap(trap) {
	std::cout << "DiamondTrap " << this->name_ << " copy constructor called" << std::endl;
	*this = trap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& trap) {
	if (this != &trap)
	{
		this->name_ = trap.name_;
		this->hit_point_ = trap.hit_point_;
		this->energy_point_ = trap.energy_point_;
		this->attack_damage_ = trap.attack_damage_;
	}
	std::cout << "DiamondTrap " << this->name_ << " operator= called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name_ << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	if (this->hit_point_ == 0 || this->energy_point_ == 0)
	{
		std::cout << "DiamondTrap " << this->name_ << " can't call itself!" << std::endl;
	}
	std::cout << "I am DiamondTrap " << this->name_ << " and ClapTrap name is " << ClapTrap::name_ << std::endl;
}

void DiamondTrap::print() {
	std::cout << "Hit point: " << hit_point_ << std::endl;
	std::cout << "Energy point: " << energy_point_ << std::endl;
	std::cout << "Attack Damage: " << attack_damage_ << std::endl;
}