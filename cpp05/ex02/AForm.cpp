#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("it's grade is too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("it's grade is too high!");
}

const char *AForm::NotSignedException::what () const throw()
{
	return ("it's not signed!");
}

const char *AForm::AlreadySigned::what() const throw()
{
	return ("it's already signed!");
}

AForm::AForm(void) : name(""), isSigned(false), gradeToSign(0), gradeToExecute(0) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
		throw (GradeTooHighException());
	if (gradeToExecute > 150 || gradeToSign > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &copyFrom)
: name(copyFrom.name), isSigned(copyFrom.isSigned), gradeToSign(copyFrom.gradeToSign), gradeToExecute(copyFrom.gradeToExecute) {}

AForm& AForm::operator=(const AForm &right)
{
	if (this != &right)
		isSigned = right.isSigned;
	return (*this);
}

AForm::~AForm(void) {}

std::string	AForm::getName(void) const
{
	return (name);
}

bool	AForm::getIsSigned(void) const
{
	return (isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (gradeToExecute);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw (GradeTooLowException());
	if (isSigned)
		throw (AlreadySigned());
	isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
		throw (NotSignedException());
	if (executor.getGrade() > gradeToExecute)
		throw (GradeTooLowException());
	callExec();
}

std::ostream& operator<<(std::ostream& out, const AForm &form)
{
	return (out << "Form name: " << form.getName() 
	<< "\nIs signed: " << (form.getIsSigned() ? "Yes" : "No")
	<< "\nGrade to sign: " << form.getGradeToSign()
	<< "\nGrade to execute: " << form.getGradeToExecute());
}
