#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
}

Dog::Dog(const Dog &copyfrom) : Animal(copyfrom) {}

Dog& Dog::operator=(const Dog &right)
{
	if (this != &right)
		type = right.type;
	return (*this);
}

Dog::~Dog(void) {}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
