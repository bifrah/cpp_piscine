#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat(const WrongCat &wrongCat);
	WrongCat(void);
	~WrongCat();

	WrongCat& operator=(const WrongCat& wrongCat);

};

#endif