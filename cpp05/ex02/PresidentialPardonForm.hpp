#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm  : public AForm {

public:

	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm&		operator= (const PresidentialPardonForm &PPform);

	virtual void	execute(Bureaucrat const &executor) const;

private:

	const std::string	_target;
};

#endif