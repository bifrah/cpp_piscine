#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Animal constructor was called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor was called." << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor was called." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& animal)
{
	std::cout << "Animal assignation copy constructor called" << std::endl;
	this->p_Type = animal.getType();
	this->p_Sound = animal.getSound();
	return (*this);
}
