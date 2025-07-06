#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copyFrom) : ClapTrap(copyFrom)
{
	std::cout << "ScavTrap " << name << " copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &right)
{
	if (this != &right)
		ClapTrap::operator=(right);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (!energyPoints)
		return (std::cout << "ScavTrap " << name << " is too weak to attack" << std::endl, (void)0);
	if (!hitPoints)
		return (std::cout << "ScavTrap " << name << " is dead " << std::endl, (void)0);
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}
