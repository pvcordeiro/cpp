#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <string>

class Bureaucrat;

class AForm
{
	protected:
		virtual void		callExec() const = 0;
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
	public:
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class AlreadySigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		AForm(void);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &copyFrom);
		AForm& operator=(const AForm &right);
		~AForm(void);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		void		beSigned(Bureaucrat &bureaucrat);
		void		execute(Bureaucrat const &executor) const;
};

std::ostream& operator<<(std::ostream &out, const AForm &form);

#endif
