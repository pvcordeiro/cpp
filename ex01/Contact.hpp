#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "main.hpp"

class Contact {

	public:
	
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		int			PhoneNumber;
		std::string	DarkestSecret;

		Contact();
		~Contact();
};

#endif