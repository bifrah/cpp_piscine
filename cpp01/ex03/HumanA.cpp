#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon_type) : _Weapon_type(weapon_type) {

	setName(name);
	std::cout << "HumanA constructor called" << std::endl;
	return ;
}

HumanA::~HumanA(void) {
	
	std::cout << "HumanA destructor called" << std::endl;
	return ;
}

void	HumanA::setName(const std::string name) {

	this->_name = name;
	return ;
}

void	HumanA::attack(void) {

	std::cout << _name << " attacks with their " << _Weapon_type.getType() << std::endl;
	return ;
}
