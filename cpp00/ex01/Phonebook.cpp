#include "Phonebook.hpp"

Phonebook::Phonebook() : contact_count(0) {}

std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

bool	checkNumber(std::string input)
{
	for (size_t i = 0; i < input.length(); ++i)
		if (!std::isdigit(input[i]))
			return (false);
	return (true);
}

bool	inputHandler(std::string prompt, std::string baseCase, t_get type, Contact& new_contact)
{
	std::string input;

	do {
		std::cout << prompt;
		if (!std::getline(std::cin, input) || std::cin.eof())
			return (false);
		if (input.empty())
			std::cout << baseCase << std::endl;
		else if (type == _PhoneNumber && !checkNumber(input))
			std::cout << "\nPhone number can only contain digits!" << std::endl;
		else
			return (new_contact.setter(input, type), true);
	} while (true);
}

bool	Phonebook::Add()
{
	Contact		new_contact;
	
	if (!inputHandler("\nEnter First Name: ", "\nFirst Name cannot be empty!", _FirstName, new_contact))
		return (false);
	if (!inputHandler("\nEnter Last Name: ", "\nLast Name cannot be empty!", _LastName, new_contact))
		return (false);
	if (!inputHandler("\nEnter Nick Name: ", "\nNick Name cannot be empty!", _NickName, new_contact))
		return (false);
	if (!inputHandler("\nEnter Phone Number: ", "\nPhone number cannot be empty!", _PhoneNumber, new_contact))
		return (false);
	if (!inputHandler("\nEnter Darkest Secret: ", "\nDarkest Secret cannot be empty!", _DarkestSecret, new_contact))
		return (false);

	if (contact_count < 8)
		contact_list[contact_count++] = new_contact;
	else
	{
		for (int i = 0; i < 7; ++i)
			contact_list[i] = contact_list[i + 1];
		contact_list[7] = new_contact;
	}

	std::cout << "\nContact added successfully!" << std::endl;
	return (true);
}

bool	Phonebook::Search()
{
	std::string	input;
	int			index;

	if (!contact_count)
		return (std::cout << "\nPhonebook empty!\n" << std::endl, true);

	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << std::endl;

	for (int i = 0; i < contact_count; ++i)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(contact_list[i].getter(_FirstName)) << "|";
		std::cout << std::setw(10) << truncate(contact_list[i].getter(_LastName)) << "|";
		std::cout << std::setw(10) << truncate(contact_list[i].getter(_NickName)) << std::endl;
	}

	do {
		std::cout << "\nSelect contact: ";
		if (!std::getline(std::cin, input) || std::cin.eof())
			return (false);
		if (input.length() == 1 && input[0] == '8')
			return (true);
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			index = input[0] - '0';
			if (index < contact_count)
				return (contact_list[index].showContactInfo(), true);
			else
				std::cout << "\nInvalid selection." << std::endl;
		}
		else
			std::cout << "\nSelect a contact (or 8 to go back to main menu)" << std::endl;
	} while (true);
	
	return (true);
}
