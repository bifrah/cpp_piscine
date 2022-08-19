#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm  : public AForm {

public:

	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm&		operator= (const RobotomyRequestForm &RRform);

	virtual void execute(Bureaucrat const &executor) const;

private:

	const std::string	_target;

	void	_robotomise(void) const;

};

#endif