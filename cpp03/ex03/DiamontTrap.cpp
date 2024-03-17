#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	this->hit_point_ = FragTrap::hit_point_;
	this->energy_point_ = ScavTrap::energy_point_;
	this->attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : {

}

DiamondTrap::DiamondTrap(const DiamondTrap& trap) {

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& trap) {

}

DiamondTrap::~DiamondTrap() {

}

void DiamondTrap::whoAmI() {

}
