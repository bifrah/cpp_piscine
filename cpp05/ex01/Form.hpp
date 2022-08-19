#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form {

public:

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Form: This grade is too high !");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Form: This grade is too low !");
			}
	};

	Form(const std::string name, const int grade_to_sign, const int grade_to_exec);
	Form(const Form& form);
	Form(void);
	~Form();

	std::string	getName(void) const;
	bool		getSigned(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExec(void) const;

	void		beSigned(Bureaucrat &bureaucrat);
	
	Form&		operator= (const Form& form);

private:

	const std::string	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_exec;

};

std::ostream&	operator<<(std::ostream &out, const Form &form);

#endif