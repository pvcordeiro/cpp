#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("it's grade is too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("it's grade is too high!");
}

Bureaucrat::Bureaucrat(void) : name("No name"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copyfrom) : name(copyfrom.name), grade(copyfrom.grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &right)
{
	if (this != &right)
		this->grade = right.grade;
	return (*this);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

int	Bureaucrat::getGrade(void) const
{
	return (grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (name);
}

void	Bureaucrat::incrementGrade(void)
{
	setGrade(grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	setGrade(grade + 1);
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat)
{
	return (out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade() << std::endl);
}
