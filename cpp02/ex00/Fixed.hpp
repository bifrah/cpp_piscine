#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:

	Fixed(const Fixed &f);
	Fixed(void);
	~Fixed();

	Fixed&	operator= (const Fixed& new_x);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int					_x;
	const static int	_bits = 8;

};

#endif