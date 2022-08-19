#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	this->p_Name = name;
	this->p_HitPoints = 100;
	this->p_EnergyPoints = 50;
	this->p_AttackDamage = 20;
	std::cout << "ScavTrap Name constructor was called." << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	*this = scavTrap;
	std::cout << "ScavTrap copy constructor was called." << std::endl;
	return ;
}

ScavTrap::ScavTrap(void)
{
	this->p_HitPoints = 100;
	this->p_EnergyPoints = 50;
	this->p_AttackDamage = 20;
	std::cout << "ScavTrap Default constructor was called." << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor was called." << std::endl;
	return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	this->p_Name = scavTrap.getName();
	this->p_HitPoints = scavTrap.getHitPoints();
	this->p_EnergyPoints = scavTrap.getEnergyPoints();
	this->p_AttackDamage = scavTrap.getAttackDamage();
	std::cout << "ScavTrap Copy assignment operator called\n" << std::endl;
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "Gate Keeper mode actived for ScavTrap " << this->getName() << std::endl;
}
