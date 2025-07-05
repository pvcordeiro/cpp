#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

typedef enum e_level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NONE
}	t_level;

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void	complain(std::string level);
};

#endif