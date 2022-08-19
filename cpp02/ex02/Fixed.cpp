#include "Fixed.hpp"

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_x = (int)(roundf(f * (1 << this->_bits)));
}

Fixed::Fixed(const int n)
{
	// std::cout << "Integer constructor called" << std::endl;
	this->_x = n << this->_bits;
}

Fixed::Fixed(const Fixed &f)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = f;
	return ;
}

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->_x = 0;
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed&	Fixed::operator= (const Fixed& new_x)
{
	// std::cout << "Copy assignment operator called" << std::endl;
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

bool Fixed::operator< (Fixed const &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator> (Fixed const &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<= (Fixed const &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator>= (Fixed const &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator== (Fixed const &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!= (Fixed const &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+ (Fixed const &fixed) const
{
	Fixed result(*this);
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator- (Fixed const &fixed) const
{
	Fixed result(*this);
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (result);
}

Fixed Fixed::operator* (Fixed const &fixed) const
{
	Fixed result(*this);
	result.setRawBits(((long)this->getRawBits() * (long)fixed.getRawBits()) / (1 << this->_bits));
	return (result);
}

Fixed Fixed::operator/ (Fixed const &fixed) const
{
	Fixed result(*this);
	if (fixed._x == 0)
	{
		std::cout << "Cant divide by zero\n";
		return (result);
	}
	result.setRawBits(((long)this->getRawBits() * (1 << this->_bits)) / (long)fixed.getRawBits());
	return (result);
}

Fixed &Fixed::operator++()
{
	this->_x += 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_x -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	operator++();
	return (result);
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	operator--();
	return (result);
}

Fixed &Fixed::min(Fixed &cmp, Fixed &fixed)
{
	if (cmp < fixed)
		return (cmp);
	return (fixed);
}

Fixed &Fixed::max(Fixed &cmp, Fixed &fixed)
{
	if (cmp > fixed)
		return (cmp);
	return (fixed);
}

Fixed const &Fixed::min(Fixed const &cmp, Fixed const &fixed)
{
	if (cmp < fixed)
		return (cmp);
	return (fixed);
}

Fixed const &Fixed::max(Fixed const &cmp, Fixed const &fixed)
{
	if (cmp > fixed)
		return (cmp);
	return (fixed);
}