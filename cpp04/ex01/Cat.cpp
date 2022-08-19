#include "Cat.hpp"

Cat::Cat(void)
{
	this->p_Type = "Cat";
	this->p_Sound = "Miaou";
	this->_brain = new Brain();
	std::cout << "Cat constructor was called." << std::endl;
}

Cat::Cat(const Cat &cat) : Animal()
{
	*this = cat;
	std::cout << "Cat copy constructor was called." << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor was called." << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat assignation copy constructor called" << std::endl;
	this->p_Type = cat.getType();
	this->p_Sound = cat.getSound();
	this->_brain = new Brain();
	return (*this);
}