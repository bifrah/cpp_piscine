#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

public:

	Cat(const Cat &cat);
	Cat(void);
	~Cat();

	Cat& operator=(const Cat& cat);

	virtual std::string	getType(void) const;
	virtual std::string	getSound(void) const;
	virtual void		makeSound(void) const;

private:

	Brain	*_brain;

};

#endif