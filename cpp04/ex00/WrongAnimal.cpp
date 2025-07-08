#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal parametered constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copyfrom) : type(copyfrom.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &right)
{
	std::cout << "WrongAnimal operator assignment called" << std::endl;
	if (this != &right)
		WrongAnimal::operator=(right);
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal generic sound" << std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return (type);
}
