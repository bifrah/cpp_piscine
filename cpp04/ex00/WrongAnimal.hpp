#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class WrongAnimal {

public:

	WrongAnimal(const WrongAnimal &wrongAnimal);
	WrongAnimal(void);
	~WrongAnimal();

	WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
	std::string	getType(void) const;
	std::string	getSound(void) const;

	void	makeSound(void) const;

protected:

	std::string	p_Type;
	std::string	p_Sound;

};

#endif