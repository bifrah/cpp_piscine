#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T tab[], int size, void fct (T const &arg))
{
	int	i = 0;

	while (i < size)
	{
		fct(tab[i]);
		i++;
	}

}

template <typename T>
void fct(T &arg)
{
	std::cout << "-> " << arg << std::endl;
}

#endif