#ifndef Phonebook_HPP
# define Phonebook_HPP

#include "Contact.hpp"

class Phonebook
{

	private:
		Contact contact_list[8];
		int		contact_count;

	public:
		Phonebook();
		bool	Add();
		bool	Search();
};

#endif