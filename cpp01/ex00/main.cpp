#include "Zombie.hpp"

int	main(void)
{
	Zombie *heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie");
	
	Zombie *anotherZombie = newZombie("AnotherHeapZombie");
	anotherZombie->announce();
	delete anotherZombie;

	return (0);
}
