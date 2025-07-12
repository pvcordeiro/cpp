#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
: AForm("Presidential Pardon Form", 25, 5), target("Default target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyFrom)
: AForm(copyFrom), target(copyFrom.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &right)
{
	if (this != &right)
	{
		AForm::operator=(right);
		target = right.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::callExec(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
