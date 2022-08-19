#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

typedef struct	s_Data
{
	int			nb;
	char		c;
	std::string	str;
}				Data;

uintptr_t		serialize(Data* ptr);
Data*			deserialize(uintptr_t raw);

std::ostream	&operator<<(std::ostream &out, const Data &ptr);

#endif