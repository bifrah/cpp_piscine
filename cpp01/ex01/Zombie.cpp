#include "Zombie.hpp"

Zombie::Zombie(void) {

	std::cout << "Zombie default constructor called" << std::endl;
	return ;
}

Zombie::~Zombie(void) {

	std::cout << "Zombie of " << this->_name << " destructor called" << std::endl;
	return ;
}

void	Zombie::announce(void) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::Setname(std::string name) {

	this->_name = name;
}