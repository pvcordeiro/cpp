#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
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
		Form(void);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form &copyFrom);
		Form& operator=(const Form &right);
		~Form(void);

		std::string	getName(void) const;
		bool			getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

		void				beSigned(Bureaucrat &bureaucrat);	
};

std::ostream& operator<<(std::ostream &out, const Form &Form);

#endif
