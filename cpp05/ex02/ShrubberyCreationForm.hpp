#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class ShrubberyCreationForm  : public AForm {

public:

	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm&		operator= (const ShrubberyCreationForm &SCform);

	virtual void execute(Bureaucrat const &executor) const;

private:

	const std::string	_target;

	void	_print_tree(void) const;

};


#endif