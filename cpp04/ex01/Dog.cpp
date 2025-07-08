#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &copyfrom) : Animal(copyfrom)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*copyfrom.brain);
}

Dog& Dog::operator=(const Dog &right)
{
	std::cout << "Dog operator assignment called" << std::endl;
	if (this != &right)
	{
		Animal::operator=(right);
		delete brain;
		brain = new Brain(*right.brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
