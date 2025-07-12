#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	protected:
		void callExec(void) const;
	private:
		std::string target;
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copyFrom);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &right);
		~RobotomyRequestForm(void);
	};

#endif
