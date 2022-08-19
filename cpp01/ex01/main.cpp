#include "Zombie.hpp"

int	main(void) {

	Zombie	*toto;
	int		i = 0;

	toto = zombieHorde(12, "Miamologue");
	while (i < 12)
		toto[i++].announce();
	delete [] toto;
}