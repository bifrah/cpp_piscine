#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
{
	this->p_Name = name;
	this->p_HitPoints = 100;
	this->p_EnergyPoints = 100;
	this->p_AttackDamage = 30;
	std::cout << "FragTrap Name constructor was called." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap &fragTrap)
{
	*this = fragTrap;
	std::cout << "FragTrap Default constructor was called." << std::endl;
	return ;
}

FragTrap::FragTrap(void)
{
	this->p_HitPoints = 100;
	this->p_EnergyPoints = 100;
	this->p_AttackDamage = 30;
	std::cout << "FragTrap Default constructor was called." << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor was called." << std::endl;
	return ;
}

FragTrap& FragTrap::operator=(const FragTrap& frag)
{
    this->p_Name = frag.getName();
    this->p_HitPoints = frag.getHitPoints();
    this->p_EnergyPoints = frag.getEnergyPoints();
    this->p_AttackDamage = frag.getAttackDamage();
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " say please HighFive me !" << std::endl;
}
