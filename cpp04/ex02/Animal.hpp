#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &copyFrom);
		Animal& operator=(const Animal &right);
		virtual ~Animal(void);

		virtual void		makeSound(void) const = 0;
		void		setType(std::string type);
		std::string	getType(void) const;
};

#endif
