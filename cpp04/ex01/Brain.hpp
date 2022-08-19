#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain {

public:

	Brain(const Brain &brain);
	Brain(void);
	~Brain();
	
	Brain& operator=(const Brain& brain);

private:

	std::string	_ideas[100];

};

#endif