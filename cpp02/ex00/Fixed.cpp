#include "Fixed.hpp"

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_x = f._x;
	return ;
}

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_x = 0;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator= (const Fixed& new_x)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_x = new_x.getRawBits();
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_x = raw;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_x);
}
