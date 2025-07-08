#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copyFrom);
		WrongAnimal& operator=(const WrongAnimal &right);
		~WrongAnimal(void);

		void		makeSound(void) const;
		void		setType(std::string type);
		std::string	getType(void) const;
};

#endif
