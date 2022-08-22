#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vect(5);

	vect[0] = 1;
	vect[1] = 2;
	vect[2] = 3;
	vect[3] = 4;
	vect[4] = 0;

	easyfind(vect, 4);
	easyfind(vect, 12);
}