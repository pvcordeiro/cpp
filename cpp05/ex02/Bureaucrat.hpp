#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copyfrom);
		Bureaucrat& operator=(const Bureaucrat &right);
		~Bureaucrat(void);

		int 	getGrade(void) const;
		std::string getName(void) const;
		void	setGrade(int grade);
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm &form);
		void	executeForm(AForm const &form) const;
};
		std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat);

#endif
