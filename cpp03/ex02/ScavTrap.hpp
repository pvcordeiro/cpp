#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copyFrom);
		ScavTrap& operator=(const ScavTrap &right);
		~ScavTrap(void);

		void attack(const std::string& target);
		void guardGate(void);
};

#endif
