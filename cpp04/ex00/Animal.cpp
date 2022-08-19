#include "Animal.hpp"

Animal::Animal(void)
{
	this->p_Type = "King Kong";
	this->p_Sound = "King Kong Sound";
	std::cout << "Animal constructor was called." << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor was called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor was called." << std::endl;
}

Animal& Animal::operator=(const Animal& animal)
{
	this->p_Type = animal.getType();
	this->p_Sound = animal.getSound();
	std::cout << "Animal assignation copy constructor called" << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->p_Type);
}

std::string	Animal::getSound(void) const
{
	return (this->p_Sound);
}

void	Animal::makeSound(void) const
{
	std::cout << this->getSound() << std::endl;
}
