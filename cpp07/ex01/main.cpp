#include "iter.hpp"
#include <cstring>

int main(void)
{
	int	int_tab[20];
	int	i = 0;

	while (i <= 19)
	{
		int_tab[i] = i * 2;
		i++;
	}

	std::string str_tab[3];
	str_tab[0] = "Hello";
	str_tab[1] = "World";
	str_tab[2] = "!";

	iter(int_tab, 20, fct);
	iter(str_tab, 3, fct);
	return (0);
}