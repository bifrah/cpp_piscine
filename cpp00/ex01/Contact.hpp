#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact {

public:

	void		SetContact(int index);
	void		ChangeIndex(void);
	void		ShowIndex(void) const ;
	std::string	ReturnFirstname(void) const ;
	std::string	ReturnLastname(void) const ;
	std::string	ReturnNickname(void) const ;
	void		ShowContact(void) const ;

	Contact(void);
	~Contact(void);

private:

	int			index;
	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_darkestsecret;

};

#endif
