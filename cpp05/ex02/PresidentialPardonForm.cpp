#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm defaut constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonform) \
: AForm("PresidentialPardonForm", 25, 5)
{
	*this = presidentialPardonform;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator= (const PresidentialPardonForm &PPform)
{
	if (this == &PPform)
		return (*this);
	std::cout << "PresidentialPardonForm assignation copy constructor called" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	std::cout << _target << " was forgiven by Zaphod Beeblebrox." << std::endl;
}
