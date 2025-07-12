#ifndef INTERN_HPP
# define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm* makeShrubberyCreationForm(const std::string &target);
		AForm* makeRobotomyRequestForm(const std::string &target);
		AForm* makePresidentialPardonForm(const std::string &target);
	public:
		Intern(void);
		Intern(const Intern &copyFrom);
		Intern& operator=(const Intern &right);
		~Intern(void);
		AForm* makeForm(std::string form, std::string target);
};

#endif
