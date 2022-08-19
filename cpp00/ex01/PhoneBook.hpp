#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdio>
#include <ctype.h>

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void);
	void	exit_phone(void);

private:

	Contact	repertory[8];
	int		index;

	void	_Trunc_and_Print_str(std::string str);
	void	_PrintTruncContact(Contact &contact);
	int		_ft_isdigit(std::string str) const ;
	int		_ft_atoi(std::string str) const ;

};

#endif
