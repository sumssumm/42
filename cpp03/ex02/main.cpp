#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap a("AAA");
	ScavTrap b("BBB");
	FragTrap c("CCC");

	std::cout << std::endl;

	a.attack("BBB");
	b.takeDamage(10);
	b.beRepaired(2);
	std::cout << "< a >" << std::endl; 
	a.print();
	std::cout << "< b >" << std::endl; 
	b.print();
	std::cout << std::endl;

	b.attack("CCC");
	c.takeDamage(20);
	c.beRepaired(10);
	std::cout << "< b >" << std::endl; 
	b.print();
	std::cout << "< c >" << std::endl; 
	c.print();
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	c.attack("AAA");
	a.takeDamage(30);
	a.beRepaired(1);
	std::cout << "< a >" << std::endl; 
	a.print();
	std::cout << "< c >" << std::endl; 
	c.print();
	std::cout << std::endl;

	c.highFiveGuys();
	std::cout << std::endl;

	return 0;
}