#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
}

Cat::Cat(const Cat &copyfrom) : Animal(copyfrom) {}

Cat& Cat::operator=(const Cat &right)
{
	if (this != &right)
		type = right.type;
	return (*this);
}

Cat::~Cat(void) {}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
