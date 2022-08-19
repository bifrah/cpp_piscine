#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

public:

	Dog(const Dog &dog);
	Dog(void);
	~Dog();
	
	Dog& operator=(const Dog& dog);
	virtual std::string	getType(void) const;
	virtual std::string	getSound(void) const;
	virtual void		makeSound(void) const;

private:

	Brain	*_brain;

};

#endif