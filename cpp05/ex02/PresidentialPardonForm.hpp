#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class	PresidentialPardonForm : public AForm
{
	protected:
		void callExec(void) const;
	private:
		std::string target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copyFrom);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &right);
		~PresidentialPardonForm(void);
	};

#endif
