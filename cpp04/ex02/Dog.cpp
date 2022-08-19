#include "Dog.hpp"

Dog::Dog(void)
{
	this->p_Type = "Dog";
	this->p_Sound = "Wouf";
	this->_brain = new Brain();
	std::cout << "Dog constructor was called." << std::endl;
}

Dog::Dog(const Dog &dog) : AAnimal()
{
	*this = dog;
	std::cout << "Dog copy constructor was called." << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor was called." << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog assignation copy constructor called" << std::endl;
	this->p_Type = dog.getType();
	this->p_Sound = dog.getSound();
	this->_brain = new Brain();
	return (*this);
}

std::string	Dog::getType(void) const
{
	return (this->p_Type);
}

std::string	Dog::getSound(void) const
{
	return (this->p_Sound);
}


void	Dog::makeSound(void) const
{
	std::cout << this->getSound() << std::endl;
}
