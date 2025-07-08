#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copyFrom);
		Cat& operator=(const Cat &right);
		~Cat(void);

		void	makeSound(void) const;
};

#endif
