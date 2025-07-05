#include "Phonebook.hpp"

int	main()
{
	Phonebook 	Phonebook;
	std::string	command;

	std::cout << std::endl << "              PhOnEbOoK" << std::endl;
	while (1)
	{
		std::cout << std::endl << "Commands available: ADD, SEARCH or EXIT\n" << std::endl;
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			return (0);
		else if (command == "ADD")
		{
			if (!Phonebook.Add())
				return (0);
		}
		else if (command == "SEARCH")
		{
			if (!Phonebook.Search())
				return (0);
		}
		else
			std::cout << "\nInvalid command. Use ADD, SEARCH or EXIT (all uppercase).\n" << std::endl;
	}
	return 0;
}