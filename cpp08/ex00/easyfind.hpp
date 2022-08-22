#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>


template <typename T>
void	easyfind(T vect, int nb)
{
	typename T::iterator i = std::find(vect.begin(), vect.end(), nb);
	if (i == vect.end())
	{
		std::cout << "We don't find your number." << std::endl;
		return ;
	}
	else
		std::cout << "We found it." << std::endl;
}

#endif