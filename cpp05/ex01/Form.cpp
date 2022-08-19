#include "Form.hpp"

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_exec) \
: _name(name), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	this->_signed = false;
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& form) \
: _name(form.getName()), _grade_to_sign(form.getGradeToSign()), _grade_to_exec(form.getGradeToExec())
{
	this->_signed = form.getSigned();
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(void) \
: _name(NULL), _grade_to_sign(0), _grade_to_exec(0)
{
	this->_signed = false;
	std::cout << "Form defaut constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string	Form::getName(void) const
{
	return (_name);
}

bool		Form::getSigned(void) const
{
	return (_signed);
}

int	Form::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int	Form::getGradeToExec(void) const
{
	return (_grade_to_exec);
}

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->getGradeToSign() >= bureaucrat.getGrade())
			this->_signed = true;
		else
			throw (Form::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
		
}

Form&		Form::operator= (const Form& form)
{
	if (this == &form)
		return (*this);
	this->_signed = form.getSigned();
	std::cout << "Form assignation copy constructor called" << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << std::endl;
	out << form.getName() << ", form grade to exec " << form.getGradeToExec() << std::endl;
	if (form.getSigned())
		out << form.getName() << ", is signed " << std::endl;
	else
		out << form.getName() << ", is not signed " << std::endl;
	return (out);
}
