#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class ClapTrap {

public:

	ClapTrap(std::string name);
	ClapTrap(ClapTrap &clapTrap);
	ClapTrap(void);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& clapTrap);
	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;
	void			printAll(void);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:

	std::string		p_Name;
	unsigned int	p_HitPoints;
	unsigned int	p_EnergyPoints;
	unsigned int	p_AttackDamage;

};

#endif