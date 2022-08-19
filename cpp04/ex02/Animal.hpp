#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class AAnimal {

public:

	AAnimal(const AAnimal &animal);
	AAnimal(void);
	virtual ~AAnimal() = 0;

	AAnimal& operator=(const AAnimal& animal);
	virtual std::string	getType(void) const = 0;
	virtual std::string	getSound(void) const = 0;

	virtual void	makeSound(void) const = 0;

protected:

	std::string	p_Type;
	std::string	p_Sound;

};

#endif