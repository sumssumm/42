#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap a("AAA");
	ScavTrap b("BBB");
	FragTrap c("CCC");

	std::cout << std::endl;

	a.attack("BBB");
	b.takeDamage(20);
	b.beRepaired(2);
	std::cout << std::endl;

	b.attack("CCC");
	c.takeDamage(30);
	c.beRepaired(10);
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	c.attack("AAA");
	a.takeDamage(10);
	a.beRepaired(1);
	std::cout << std::endl;

	c.highFiveGuys();
	std::cout << std::endl;

	return 0;
}