#include "Fixed.hpp"

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_x = (int)(roundf(f * (1 << this->_bits)));
}

Fixed::Fixed(const int n)
{
	std::cout << "Integer constructor called" << std::endl;
	this->_x = n << this->_bits;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
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
	// std::cout << "setRawBits member function called" << std::endl;
	this->_x = raw;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_x);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_x / (float)(1 << this->_bits));
}

int		Fixed::toInt(void) const
{
	return ((int)(this->_x >> this->_bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

// 123456789 a virgule fixe peut etre represente ainsi :
// 1234567.89
// 123456.78
// 12345.67
// 1234.56
// 123.45
// 12.34
// 1.23