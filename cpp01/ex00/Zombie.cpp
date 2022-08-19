#include "Zombie.hpp"

Zombie::Zombie(std::string name) {

	this->_name = name;
	std::cout << "Zombie constructor " << name << " called" << std::endl;
	return ;
}

Zombie::~Zombie(void) {

	std::cout << "Zombie " << this->_name << " destructor called" << std::endl;
	return ;
}

void	Zombie::announce(void) {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
