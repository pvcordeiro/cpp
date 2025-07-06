#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &copyFrom);
		FragTrap& operator=(const FragTrap &right);
		~FragTrap(void);

		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
