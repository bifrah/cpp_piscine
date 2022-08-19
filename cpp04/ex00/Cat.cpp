#include "Cat.hpp"

Cat::Cat(void)
{
	this->p_Type = "Cat";
	this->p_Sound = "Miaou";
	std::cout << "Cat constructor was called." << std::endl;
}

Cat::Cat(const Cat &cat) : Animal()
{
	*this = cat;
	std::cout << "Cat copy constructor was called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor was called." << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	this->p_Type = cat.getType();
	this->p_Sound = cat.getSound();
	std::cout << "Cat assignation copy constructor called" << std::endl;
	return (*this);
}