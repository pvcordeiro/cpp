#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}
Brain::Brain(const Brain &copyFrom)
{
	std::cout << "Brain copy contrutor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = copyFrom.ideas[i];
}

Brain& Brain::operator=(const Brain &right)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = right.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}
