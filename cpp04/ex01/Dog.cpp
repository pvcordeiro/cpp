#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copyfrom) : Animal(copyfrom)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &right)
{
	std::cout << "Dog operator assignment called" << std::endl;
	if (this != &right)
		type = right.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
