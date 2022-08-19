#include "Dog.hpp"

Dog::Dog(void)
{
	this->p_Type = "Dog";
	this->p_Sound = "Wouf";
	std::cout << "Dog constructor was called." << std::endl;
}

Dog::Dog(const Dog &dog) : Animal()
{
	*this = dog;
	std::cout << "Dog copy constructor was called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor was called." << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	this->p_Type = dog.getType();
	this->p_Sound = dog.getSound();
	std::cout << "Dog assignation copy constructor called" << std::endl;
	return (*this);
}