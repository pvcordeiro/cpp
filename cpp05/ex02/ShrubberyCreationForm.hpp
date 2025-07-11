#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	protected:
		void callExec(void) const;
	private:
		std::string target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copyFrom);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &right);
		~ShrubberyCreationForm(void);
	};

#endif
