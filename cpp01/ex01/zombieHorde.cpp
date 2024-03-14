#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie	*zombie = new Zombie[N];
	std::stringstream	ss;
	
	for (int i = 0; i < N; i++)
	{
		ss.str(std::string());
		ss << i + 1;
		zombie[i].setName(name + ss.str());
	}
	return zombie;
}
