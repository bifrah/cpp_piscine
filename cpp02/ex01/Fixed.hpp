#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

public:

	Fixed(const float f);
	Fixed(const int n);
	Fixed(const Fixed &f);
	Fixed(void);
	~Fixed();

	Fixed&	operator= (const Fixed& new_x);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	int					_x;
	const static int	_bits = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif