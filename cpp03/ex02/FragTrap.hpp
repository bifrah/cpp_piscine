#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap{

public :

	FragTrap(std::string name);
	FragTrap(FragTrap &fragTrap);
	FragTrap(void);
	~FragTrap();

	FragTrap& operator=(const FragTrap& frag);
	void	highFivesGuys(void);

};

#endif