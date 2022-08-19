#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public :

	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap(void);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& scavTrap);
	void guardGate(void);

};

#endif