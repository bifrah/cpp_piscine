#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class Animal {

public:

	Animal(const Animal &animal);
	Animal(void);
	virtual ~Animal();

	Animal& operator=(const Animal& animal);
	std::string	getType(void) const;
	std::string	getSound(void) const;

	void	makeSound(void) const;

protected:

	std::string	p_Type;
	std::string	p_Sound;

};

#endif