#include "ScavTrap.hpp"

int	main() {

	ScavTrap	Player1("Altanel");
	ScavTrap	Player2("Anxiolite");


	Player1.printAll();
	Player2.printAll();
	Player1.attack(Player2.getName());
	Player2.takeDamage(Player1.getAttackDamage());
	Player1.printAll();
	Player2.printAll();
	Player2.beRepaired(10);
	Player1.printAll();
	Player2.printAll();
	Player2.guardGate();
}