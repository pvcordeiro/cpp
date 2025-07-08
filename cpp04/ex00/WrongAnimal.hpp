#ifndef WRONGANIMAL_CPP
# define WRONGANIMAL_CPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copyFrom);
		WrongAnimal& operator=(const WrongAnimal &right);
		~WrongAnimal(void);

		void		makeSound(void) const;
		void		setType(std::string type);
		std::string	getType(void) const;
};

#endif
