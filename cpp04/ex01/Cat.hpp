#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

public:

	Cat(const Cat &cat);
	Cat(void);
	~Cat();

	Cat& operator=(const Cat& cat);

private:

	Brain	*_brain;

};

#endif