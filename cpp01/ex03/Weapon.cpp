#include "Weapon.hpp"

Weapon::Weapon(std::string type) {

	this->_type = type;
	std::cout << "Weapon constructor called" << std::endl;
	return ;
}

Weapon::Weapon(void) {

	std::cout << "Weapon default constructor called" << std::endl;
	return ;
}

Weapon::~Weapon(void) {

	std::cout << "Weapon destructor called" << std::endl;
	return ;
}

const std::string&	Weapon::getType(void) {

	return (this->_type);
}

void				Weapon::setType(std::string newType) {

	this->_type = newType;
}
