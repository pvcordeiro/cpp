#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &copyfrom) : Animal(copyfrom)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*copyfrom.brain);
}

Cat& Cat::operator=(const Cat &right)
{
	std::cout << "Cat operator assignment called" << std::endl;
	if (this != &right)
	{
		Animal::operator=(right);
		delete brain;
		brain = new Brain(*right.brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
