#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copyFrom) : ClapTrap(copyFrom)
{
	std::cout << "FragTrap " << name << " copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &right)
{
	if (this != &right)
		ClapTrap::operator=(right);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
		return (std::cout << "FragTrap " << name << " is too weak to attack" << std::endl, (void)0);
	if (hitPoints <= 0)
		return (std::cout << "FragTrap " << name << " is dead " << std::endl, (void)0);
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " gave a high five!!!!" << std::endl;
}
