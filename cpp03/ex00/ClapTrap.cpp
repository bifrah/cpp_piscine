#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->p_Name = name;
	this->p_HitPoints = 10;
	this->p_EnergyPoints = 10;
	this->p_AttackDamage = 0;
	std::cout << "Name constructor was called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap &clapTrap) : p_HitPoints(clapTrap.getHitPoints()), p_EnergyPoints(clapTrap.getEnergyPoints()), p_AttackDamage(clapTrap.getAttackDamage())
{
	std::cout << "Copy constructor was called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(void)
{
	this->p_HitPoints = 10;
	this->p_EnergyPoints = 10;
	this->p_AttackDamage = 0;
	std::cout << "Default constructor was called." << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor was called." << std::endl;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    this->p_Name = clapTrap.getName();
    this->p_HitPoints = clapTrap.getHitPoints();
    this->p_EnergyPoints = clapTrap.getEnergyPoints();
    this->p_AttackDamage = clapTrap.getAttackDamage();
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return (*this);
}

std::string	ClapTrap::getName(void) const
{
	return (this->p_Name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->p_HitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->p_EnergyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->p_AttackDamage);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->p_EnergyPoints > 0 && this->p_HitPoints != 0)
	{
		this->p_EnergyPoints--;
		std::cout << "ClapTrap " << this->p_Name << " attack " << target << ", causing " << this->p_AttackDamage << " points of damage !" << std::endl;
	}
	else
		std::cout << "You don't have enough EnergyPoints to attack or you are dead !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->p_HitPoints >= amount)
	{
		this->p_HitPoints -= amount;
		std::cout << this->p_Name << " loose " << amount << " Hit Point !" << std::endl;
	}
	else
	{
		this->p_HitPoints = 0;
		std::cout << this->p_Name << " is dead !" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->p_EnergyPoints > 0)
	{
		this->p_EnergyPoints--;
		this->p_HitPoints += amount;
		std::cout << this->p_Name << " repair " << amount << " of Hit Points" << std::endl;
	}
	else
		std::cout << "You don't have enough EnergyPoints to repair !" << std::endl;
}

void	ClapTrap::printAll(void)
{
	std::cout << std::endl;
	std::cout << this->p_Name << " have :" << std::endl;
	std::cout << this->p_HitPoints << " Hit Points." << std::endl;
	std::cout << this->p_EnergyPoints << " Energy Points." << std::endl;
	std::cout << this->p_AttackDamage << " Attack Damage." << std::endl;
	std::cout << std::endl;

}