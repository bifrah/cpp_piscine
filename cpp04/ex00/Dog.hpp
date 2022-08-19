#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

public:

	Dog(const Dog &dog);
	Dog(void);
	~Dog();

	Dog& operator=(const Dog& dog);

};

#endif