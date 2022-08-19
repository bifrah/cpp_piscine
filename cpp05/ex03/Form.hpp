#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Bureaucrat.hpp"


class Bureaucrat;

class AForm {

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
	class AlreadySigned : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Form: This form is already signed !");
			};
	};
	class NotSigned : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Form: This form is not signed !");
			};
	};

	AForm(const std::string name, const int grade_to_sign, const int grade_to_exec);
	AForm(const AForm& form);
	virtual ~AForm();
	AForm&			operator= (const AForm& form);

	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getGradeToSign(void) const;
	int				getGradeToExec(void) const;

	void			beSigned(Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

private:

	const std::string	_name;
	bool				_signed;
	const int			_grade_to_sign;
	const int			_grade_to_exec;

};

std::ostream&	operator<< (std::ostream &out, const AForm &form);

#endif