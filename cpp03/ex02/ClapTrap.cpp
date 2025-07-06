#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Claptrap " << name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copyFrom)
	: name(copyFrom.name), hitPoints(copyFrom.hitPoints), energyPoints(copyFrom.energyPoints), attackDamage(copyFrom.attackDamage)
{
	std::cout << "ClapTrap " << name << " copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &right)
{
	if (this != &right)
	{
		name = right.name;
		hitPoints = right.hitPoints;
		energyPoints = right.energyPoints;
		attackDamage = right.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (!energyPoints)
		return (std::cout << "ClapTrap " << name << " is too weak to attack" << std::endl, (void)0);
	if (!hitPoints)
		return (std::cout << "ClapTrap " << name << " is dead " << std::endl, (void)0);
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!hitPoints)
		return (std::cout << name << " is dead" << std::endl, (void)0);
	hitPoints -= amount;
	if (hitPoints < 0)
		hitPoints = 0;
	std::cout << name << " took " << amount << " damage " << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energyPoints)
		return (std::cout << name << " has no energy to repair itself" << std::endl, (void)0);
	hitPoints += amount;
	std::cout << name << " repaired itself with " << amount << " points. HP: " << hitPoints << std::endl;
	--energyPoints;
}
