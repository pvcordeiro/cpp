#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooLowException::what() const throw()
{
	return ("it's grade is too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("it's grade is too high!");
}

const char *Form::AlreadySigned::what () const throw()
{
	return ("it's already signed.");
}

Form::Form(void) : name(""), isSigned(false), gradeToSign(0), gradeToExecute(0) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &copyFrom)
: name(copyFrom.name), isSigned(copyFrom.isSigned), gradeToSign(copyFrom.gradeToSign), gradeToExecute(copyFrom.gradeToExecute) {}

Form& Form::operator=(const Form &right)
{
	if (this != &right)
		isSigned = right.isSigned;
	return (*this);
}

Form::~Form(void) {}

std::string	Form::getName(void) const
{
	return (name);
}

bool	Form::getIsSigned(void) const
{
	return (isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (gradeToExecute);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw (GradeTooLowException());
	if (isSigned)
		throw (AlreadySigned());
	isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
	return (out << "Form name: " << form.getName() 
	<< "\nIs signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< "\nGrade to sign: " << form.getGradeToSign()
	<< "\nGrade to execute: " << form.getGradeToExecute());
}
