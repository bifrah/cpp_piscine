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

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	this->_grade = bureaucrat.getGrade();
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

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::incrGrade(void)
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void		Bureaucrat::decrGrade(void)
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void		Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
		std::cout << form.getName() << " is already signed." << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			return ;
		}
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	std::cout << this->_name << " executed " << form.getName() << " form." << std::endl;
}

Bureaucrat&	Bureaucrat::operator= (const Bureaucrat &bureaucrat)
{
	if (this == &bureaucrat)
		return (*this);
	std::string &n = const_cast<std::string &>(this->_name);
	n = bureaucrat.getName();
	_grade = bureaucrat.getGrade();
	std::cout << "Bureaucrat assignation copy constructor called" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}