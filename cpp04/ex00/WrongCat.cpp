#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copyfrom) : WrongAnimal(copyfrom) {}

WrongCat& WrongCat::operator=(const WrongCat &right)
{
	if (this != &right)
		type = right.type;
	return (*this);
}

WrongCat::~WrongCat(void) {}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
