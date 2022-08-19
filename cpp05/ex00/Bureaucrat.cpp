#include "Bureaucrat.hpp"
	
Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	this->_grade = grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	*this = bureaucrat;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat defaut constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::incrGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decrGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

Bureaucrat&	Bureaucrat::operator= (const Bureaucrat& bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	std::string &name = const_cast<std::string &>(this->_name);
	name = bureaucrat.getName();
	_grade = bureaucrat.getGrade();
	std::cout << "Bureaucrat assignation copy constructor called" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}