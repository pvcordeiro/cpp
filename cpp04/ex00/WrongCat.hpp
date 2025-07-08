#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat &copyFrom);
		WrongCat& operator=(const WrongCat &right);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif
