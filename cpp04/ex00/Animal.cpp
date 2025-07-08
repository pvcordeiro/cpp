#include "Animal.hpp"

Animal::Animal(void) {}

Animal::Animal(const Animal &copyfrom) : type(copyfrom.type) {}

Animal& Animal::operator=(const Animal &right)
{
	if (this != &right)
		type = right.type;
	return (*this);
}

Animal::~Animal(void) {}

void	Animal::makeSound(void) const
{
	std::cout << "Animal generic sound" << std::endl;
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return (type);
}
