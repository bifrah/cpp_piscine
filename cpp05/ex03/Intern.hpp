#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <iomanip>
# include <cstring>
# include <fstream>
# include "Form.hpp"

class Intern {

public:

	class WrongName : public std::exception
	{
		public:
			const char *what() const throw() {
				return("Intern: Could not create the form : wrong name !");
			}
	};

	Intern(void);
	~Intern();

	AForm *makeForm(std::string name, std::string target);

};

#endif