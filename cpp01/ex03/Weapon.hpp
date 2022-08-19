#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

public:

	Weapon(std::string type);
	Weapon(void);
	~Weapon(void);

	const std::string&	getType(void);
	void				setType(std::string newType);

private:

	std::string	_type;
};

#endif
