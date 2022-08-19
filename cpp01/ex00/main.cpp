#include "Zombie.hpp"

int	main(void) {

	Zombie	a("toto");
	Zombie	b("titi");
	Zombie	c("tutu");
	Zombie	*toto;

	a.announce();
	b.announce();
	c.announce();
	toto = newZombie("titi2");
	toto->announce();
	randomChump("tutu2");

	delete toto;
}