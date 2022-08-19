#include "Contact.hpp"

Contact::Contact(void) {

	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void) {

	std::cout << "Contact destructor called" << std::endl;
	return;
}

void	Contact::ShowIndex(void) const {

	std::cout << this->index;
}
std::string	Contact::ReturnFirstname(void) const {

	return (this->_firstname);
}

std::string	Contact::ReturnLastname(void) const {

	return (this->_lastname);
}
std::string	Contact::ReturnNickname(void) const {

	return (this->_nickname);
}
void	Contact::ShowContact(void) const {
	
	std::cout << "Index		: " << this->index << std::endl;
	std::cout << "Firstname	: " << this->_firstname << std::endl;
	std::cout << "Lastname	: " << this->_lastname << std::endl;
	std::cout << "Nickname	: " << this->_nickname << std::endl;
	std::cout << "Phonenumber	: " << this->_phonenumber << std::endl;
	std::cout << "Darkestsecret	: " << this->_darkestsecret << std::endl;

}

void	Contact::SetContact(int index) {

	int	i = 0;

	this->index = index;
	std::cout << "Please enter the firstname : ";
	std::getline(std::cin, this->_firstname);
	if (std::cin.eof())
    	return ;
	std::cout << "Please enter his lastname : ";
	std::getline(std::cin, this->_lastname);
	if (std::cin.eof())
    	return ;
	std::cout << "Please enter his nickname : ";
	std::getline(std::cin, this->_nickname);
	if (std::cin.eof())
    	return ;
	std::cout << "Please enter his phonenumber : ";
	std::getline(std::cin, this->_phonenumber);
	if (std::cin.eof())
    	return ;
	while (this->_phonenumber[i] && !std::isdigit(this->_phonenumber[i]))
	{
		std::cout << "Please retry with only numbers : ";
		std::getline(std::cin, this->_phonenumber);
		if (std::cin.eof())
			return ;
		while (std::isdigit(this->_phonenumber[i]))
			i++;
	}
	std::cout << "Please enter his darkest secret : ";
	std::getline(std::cin, this->_darkestsecret);
	if (std::cin.eof())
    	return ;
	std::cout << "Your contact is now added" << std::endl;
}

void	Contact::ChangeIndex(void) {

	this->index--;
}