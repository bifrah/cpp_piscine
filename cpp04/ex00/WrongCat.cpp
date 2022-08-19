#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->p_Type = "WrongCat";
	this->p_Sound = "WrongMiaou";
	std::cout << "WrongCat constructor was called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal()
{
	*this = wrongCat;
	std::cout << "WrongCat constructor was called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor was called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
	this->p_Type = wrongCat.getType();
	this->p_Sound = wrongCat.getSound();
	std::cout << "WrongCat assignation copy constructor called" << std::endl;
	return (*this);
}
