#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(void);
		Dog(const Dog &copyFrom);
		Dog& operator=(const Dog &right);
		~Dog(void);

		void	makeSound(void) const;
};

#endif
