#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--------------------------------------" << std::endl;
	Animal	*meta[6];
	int		i = 0;

	while (i < 3)
	{
		meta[i] = new Dog();
		meta[i]->makeSound();
		i++;
	}
	while (i <= 5)
	{
		meta[i] = new Cat();
		meta[i]->makeSound();
		i++;
	}
	std::cout << "--------------------------------------" << std::endl;
	i = 0;
	while (i < 6)
		delete meta[i++];
	std::cout << "--------------------------------------" << std::endl;
	return (0);
}
