#include "DiamondTrap.hpp"

int main() {
	ClapTrap a("AAA");
	ScavTrap b("BBB");
	FragTrap c("CCC");
	DiamondTrap d("DDD");

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

	c.attack("DDD");
	d.takeDamage(10);
	d.beRepaired(1);
	std::cout << std::endl;

	c.highFiveGuys();
	std::cout << std::endl;

	d.attack("AAA");
	a.takeDamage(10);
	a.beRepaired(3);
	std::cout << std::endl;

	d.whoAmI();
	d.print();
	std::cout << std::endl;

	return 0;
};