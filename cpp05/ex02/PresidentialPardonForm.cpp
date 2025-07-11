#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
: AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyFrom)
: AForm(copyFrom) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &right)
{
	if (this != &right)
		AForm::operator=(right);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::callExec(void) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
