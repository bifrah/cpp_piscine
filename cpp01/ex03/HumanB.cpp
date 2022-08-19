#include "HumanB.hpp"

HumanB::HumanB(const std::string name) {

	_Weapon_type = NULL;
	setName(name);
	std::cout << "HumanB constructor called" << std::endl;
	return;
}

HumanB::~HumanB(void) {
	
	std::cout << "HumanB destructor called" << std::endl;
	return ;
}

void	HumanB::setName(const std::string name) {

	this->_name = name;
	return ;
}

void	HumanB::setWeapon(Weapon &weapon) {

	this->_Weapon_type = &weapon;
	return ;
}	

void	HumanB::attack(void) {

	std::cout << _name << " attacks with their " << _Weapon_type->getType() << std::endl;
	return ;
}
