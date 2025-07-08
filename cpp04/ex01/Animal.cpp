#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copyfrom) : type(copyfrom.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &right)
{
	std::cout << "Animal operator assignment called" << std::endl;
	if (this != &right)
		type = right.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

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
