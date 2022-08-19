#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->p_Type = "Pikachu";
	this->p_Sound = "Pika Pika !";
	std::cout << "WrongAnimal constructor was called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
	std::cout << "Animal copy constructor was called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor was called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	this->p_Type = wrongAnimal.getType();
	this->p_Sound = wrongAnimal.getSound();
	std::cout << "WrongAnimal assignation copy constructor called" << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->p_Type);
}

std::string	WrongAnimal::getSound(void) const
{
	return (this->p_Sound);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getSound() << std::endl;
}
