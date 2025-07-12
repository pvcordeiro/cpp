#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
: AForm("Shrubbery Creation Form", 145, 137), target("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyFrom)
: AForm(copyFrom), target(copyFrom.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &right)
{
	if (this != &right)
	{
		AForm::operator=(right);
		target = right.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::callExec(void) const
{
	std::ofstream file((target + "_shrubbery").c_str());
	
	for (int i = 0; i < 5; ++i)
	{
		file << "    ccee88oo\n";
        file << "  C8O8O8Q8PoOb o8oo\n";
        file << " dOB69QO8PdUOpugoO9bD\n";
        file << "CgggbU8OU qOp qOdoUOdcb\n";
        file << "    6OuU  /p u gcoUodpP\n";
        file << "      \\\\//  /douUP\n";
        file << "        \\\\////\n";
        file << "         |||/\\\n";
        file << "         |||\\/\n";
        file << "         |||||\n\n";
	}
	file.close();
}
