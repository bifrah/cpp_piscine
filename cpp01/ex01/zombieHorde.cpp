#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {

	int		i = 0;
	Zombie	*newH = new Zombie[N];

	while (i < N)
	{
		newH[i].Setname(name);
		i++;
	}
	return (newH);
}
