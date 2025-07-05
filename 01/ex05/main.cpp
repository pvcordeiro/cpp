#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (std::cout << "Usage: ./harl <level>" << std::endl ,1);
	Harl	harl;

	harl.complain((std::string)argv[1]);
	return (0);
}