#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copyfrom) : Animal(copyfrom)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &right)
{
	std::cout << "Cat operator assignment called" << std::endl;
	if (this != &right)
		type = right.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
