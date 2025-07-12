#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
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

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
	} catch (const std::exception &e) {
		std::cout << name << " couldn't sign "
		<< form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << name << " couldn't execute "
		<< form.getName() << " because " << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat)
{
	return (out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade());
}
