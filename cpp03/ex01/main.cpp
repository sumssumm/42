#include "ScavTrap.hpp"

int main() {
	ClapTrap a("AAA");
	ScavTrap b("BBB");

	std::cout << std::endl;

	a.attack("BBB");
	b.takeDamage(20);
	b.takeDamage(20);
	b.takeDamage(20);
	b.takeDamage(20);
	b.beRepaired(2);
	std::cout << std::endl;

	b.attack("AAA");
	b.attack("AAA");
	b.attack("AAA");
	b.attack("AAA");
	b.attack("AAA");
	a.takeDamage(20);
	a.beRepaired(2);
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	return 0;
}