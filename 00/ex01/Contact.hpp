#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

typedef enum e_get
{
	_FirstName,
	_LastName,
	_NickName,
	_PhoneNumber,
	_DarkestSecret
}	t_get;

class Contact
{

	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

	public:
		Contact();

		void		setter(std::string data, t_get type);
		std::string	getter(t_get type);

		void		showContactInfo();
};

#endif