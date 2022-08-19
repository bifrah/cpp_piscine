#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) \
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestform) \
: AForm("RobotomyRequestForm", 72, 45)
{
	*this = robotomyRequestform;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator= (const RobotomyRequestForm &RRform)
{
	if (this == &RRform)
		return (*this);
	std::cout << "RobotomyRequestForm assignation copy constructor called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::_robotomise(void) const
{
	srand(time(NULL));
	std::cout << "Brrrrrrr" << std::endl;
	if (rand() % 2)
		std::cout << _target << " was robotomise with succes" << std::endl;
	else
		std::cout << "RobotomyRequestForm failed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	_robotomise();
}