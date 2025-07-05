#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("HumanA Bob", club);
	bob.attack();
	club.setType("knife");
	bob.attack();
}
std::cout << std::endl;
{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("HumanB Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("laser gun");
	jim.attack();
}
	return (0);
}