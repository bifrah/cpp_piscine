#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "--------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " : Dog" << std::endl;
	std::cout << i->getType() << " : Cat" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "--------------------------------------" << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << "--------------------------------------" << std::endl;

	std::cout << "--------------------------------------" << std::endl;
	const WrongAnimal* metaPokemon = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << k->getType() << " : WrongCat" << std::endl;
	k->makeSound(); //will output the wrongcat sound!
	metaPokemon->makeSound();
	std::cout << "--------------------------------------" << std::endl;
	delete metaPokemon;
	delete k;
	std::cout << "--------------------------------------" << std::endl;
	return (0);
}