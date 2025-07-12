#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copyFrom) {(void)copyFrom;}

Intern& Intern::operator=(const Intern &right)
{
	(void)right;
	return (*this);
}

Intern::~Intern(void) {}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			switch (i)
			{
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "Error: Form '" << form << "' does not exist" << std::endl;
	return (NULL);
}
