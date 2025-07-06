#include "Zombie.hpp"

int	main(void)
{
	int		N = 5;
	Zombie *zombies = zombieHorde(N, "joselito");

	if (!zombies)
		return (std::cout << "Error: Invalid number of zombies" << std::endl, 1);

	for (int i = 0; i < N; ++i)
		zombies[i].announce();
	std::cout << std::endl;
	delete[] zombies;
	return (0);
}
