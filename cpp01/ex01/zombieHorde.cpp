#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie	*zombie = new(std::nothrow) Zombie[N];
	if (!zombie)
		std::cout << "new fail" << std::endl;

	std::stringstream	ss;
	
	for (int i = 0; i < N; i++)
	{
		ss.str("");
		ss << i + 1;
		zombie[i].setName(name + ss.str());
	}
	return zombie;
}
