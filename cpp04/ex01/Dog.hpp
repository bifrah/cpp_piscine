#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

public:

	Dog(const Dog &dog);
	Dog(void);
	~Dog();
	
	Dog& operator=(const Dog& dog);

private:

	Brain	*_brain;

};

#endif