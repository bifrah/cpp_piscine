#include "Harl.hpp"

Harl::Harl(void) {

	std::cout << "Harl constructor called" << std::endl;
	return;
}

Harl::~Harl(void) {
	
	std::cout << "Harl destructor called" << std::endl;
	return ;
}

void	Harl::debug(void) {

	std::cout << "Harl debug called" << std::endl;
	return ;
}

void	Harl::info(void) {

	std::cout << "Harl info called" << std::endl;
	return ;
}	

void	Harl::warning(void) {

	std::cout << "Harl warning called" << std::endl;
	return ;
}

void	Harl::error(void) {

	std::cout << "Harl error called" << std::endl;
	return ;
}

void	Harl::complain(std::string level) {

	void				(Harl::*p[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	const std::string	str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					i = 0;

	while(i < 4)
	{
		if (level.compare(str[i]) == 0)
		{
			(this->*p[i])();
			return ;
		}
		i++;
	}
	if (i == 4)
		std::cout << "Please enter only : DEBUG, INFO, WARNING or ERROR." << std::endl;
	return ;
}
