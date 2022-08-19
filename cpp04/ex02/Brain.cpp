#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor was called." << std::endl;
}

Brain::Brain(const Brain &brain)
{
    int i;

    i = 0;
    while (i < 100)
    {
        this->_ideas[i] = brain._ideas[i];
        i++;
    }
    std::cout << "Brain's copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor was called." << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
    int i;

    i = 0;
    while (i < 100)
    {
        this->_ideas[i] = brain._ideas[i];
        i++;
    }
    std::cout << "Brain assignation copy constructor called" << std::endl;
    return (*this);
}