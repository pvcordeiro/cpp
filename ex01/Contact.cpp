#include "Contact.hpp"

Contact::Contact() : FirstName(""), LastName(""), NickName(""), PhoneNumber(""), DarkestSecret(""){};

void	Contact::setter(std::string data, t_get type)
{
	switch (type)
	{
		case _FirstName:
			this->FirstName = data;
			break;
		case _LastName:
			this->LastName = data;
			break;
		case _NickName:
			this->NickName = data;
			break;
		case _PhoneNumber:
			this->PhoneNumber = data;
			break;
		case _DarkestSecret:
			this->DarkestSecret = data;
			break;
		default:
			break;
	}
}

std::string Contact::getter(t_get type)
{
	switch (type)
	{
		case _FirstName:
			return this->FirstName;
		case _LastName:
			return this->LastName;
		case _NickName:
			return this->NickName;
		case _PhoneNumber:
			return this->PhoneNumber;
		case _DarkestSecret:
			return this->DarkestSecret;
		default:
			return "";
	}
}

void Contact::showContactInfo()
{
	std::cout << "First Name: " << this->FirstName << std::endl;
	std::cout << "Last Name: " << this->LastName << std::endl;
	std::cout << "Nick Name: " << this->NickName << std::endl;
	std::cout << "Phone Number: " << this->PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->DarkestSecret << std::endl;
	std::cout << std::endl;
}