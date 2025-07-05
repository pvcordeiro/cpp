#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	std::string nName;

	for (int i = 0; i < N; ++i)
	{
		nName = name + std::to_string(i);
		zombies[i].setName(nName);
	}
	return (zombies);
}