#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Bureaucrat: This grade is too high !");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return("Bureaucrat: This grade is too low !");
			}
	};

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat(void);
	virtual ~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		incrGrade();
	void		decrGrade();

	Bureaucrat&	operator= (const Bureaucrat& bureaucrat);

private:

	std::string	_name;
	int			_grade;

};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif