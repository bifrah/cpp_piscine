#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {

public:

	HumanA(const std::string name, Weapon &weapon_type);
	~HumanA(void);

	void	setName(const std::string name);
	
	void	attack(void);

private:

	std::string	_name;
	Weapon		&_Weapon_type;
};

#endif
