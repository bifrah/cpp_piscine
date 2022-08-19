#include "Intern.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *CreateShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *CreateRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *CreatePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string tab[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*forms[3])(std::string) = {&CreateShrubberyCreationForm, &CreateRobotomyRequestForm, &CreatePresidentialPardonForm};
		
	int	i = 0;

	while (i < 3)
	{
		if (tab[i].compare(name) == 0)
		{
			std::cout << "Intern creates " << name << " form"<< std::endl;
			return (forms[i](target));
		}
		i++;
	}
	throw (Intern::WrongName());
}