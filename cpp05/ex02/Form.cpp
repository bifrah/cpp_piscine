#include "Form.hpp"

AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_exec) \
: _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm(const AForm& form) \
: _name(form.getName()), _grade_to_sign(form.getGradeToSign()), _grade_to_exec(form.getGradeToExec())
{
	this->_signed = form.getSigned();
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string	AForm::getName(void) const
{
	return (_name);
}

bool		AForm::getSigned(void) const
{
	return (_signed);
}

int			AForm::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int			AForm::getGradeToExec(void) const
{
	return (_grade_to_exec);
}

void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
		this->_signed = true;
	else
		throw (AForm::GradeTooLowException());
}

AForm&		AForm::operator= (const AForm& form)
{
	if (this == &form)
		return (*this);
	this->_signed = form.getSigned();
	std::cout << "Form assignation copy constructor called" << std::endl;
	return (*this);
}

std::ostream&	operator<< (std::ostream &out, const AForm &form)
{
	out << form.getName() << ", form grade to sign " << form.getGradeToSign() << std::endl;
	out << form.getName() << ", form grade to exec " << form.getGradeToExec() << std::endl;
	if (form.getSigned())
		out << form.getName() << ", is signed " << std::endl;
	else
		out << form.getName() << ", is not signed " << std::endl;
	return (out);
}
