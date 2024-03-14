#include "Zombie.hpp"

int main(void) {
	Zombie	zombie1("mainZombie1");
	zombie1.announce();

	randomChump("stackZombie2");

	Zombie	*zombie3 = newZombie("heapZombie3");
	zombie3->announce();
	delete zombie3;

	return 0;
}