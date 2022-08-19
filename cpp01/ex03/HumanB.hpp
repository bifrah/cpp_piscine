#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {

public:

	HumanB(const std::string name);
	~HumanB(void);

	void	setName(const std::string name);
	void	setWeapon(Weapon &weapon);

	void	attack(void);

private:

	std::string	_name;
	Weapon		*_Weapon_type;
};

#endif
