#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {}

WrongAnimal::WrongAnimal(const WrongAnimal &copyfrom) : type(copyfrom.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &right)
{
	if (this != &right)
		type = right.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {}

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
