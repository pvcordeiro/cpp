#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(const Animal &copyFrom);
		Animal& operator=(const Animal &right);
		~Animal(void);

		virtual void		makeSound(void) const;
		void		setType(std::string type);
		std::string	getType(void) const;
};

#endif
