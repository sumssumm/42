#include "ClapTrap.hpp"

int main() {
	ClapTrap a;
	ClapTrap b("BBB");

	a = ClapTrap("AAA");

	std::cout << std::endl;

	a.attack("BBB");
	b.takeDamage(9);
	b.beRepaired(2);
	std::cout << "< a >" << std::endl; 
	a.print();
	std::cout << "< b >" << std::endl; 
	b.print();
	std::cout << std::endl;

	b.attack("AAA");
	a.takeDamage(10);
	a.beRepaired(1);
	std::cout << "< a >" << std::endl; 
	a.print();
	std::cout << "< b >" << std::endl; 
	b.print();
	std::cout << std::endl;

	return 0;
}
