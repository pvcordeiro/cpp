#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &copyFrom) {(void)copyFrom;}

Intern& Intern::operator=(const Intern &right)
{
	(void)right;
	return (*this);
}

Intern::~Intern(void) {}

AForm* Intern::makeShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formCreators[3])(const std::string &target) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (this->*formCreators[i])(target);
		}
	}
	std::cout << "Error: Form '" << form << "' does not exist" << std::endl;
	return (NULL);
}
