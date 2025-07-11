#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyFrom)
: AForm(copyFrom) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &right)
{
	if (this != &right)
		AForm::operator=(right);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::callExec(void) const
{
	std::cout << " \"...DRILLING NOISES...\" " << std::endl;
	static int toggle = 0;
	toggle++;
	if (toggle % 2)
		std::cout << target << " has been succesfully robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
