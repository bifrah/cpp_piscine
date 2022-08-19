#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int	main()
{
	std::string	buff;
	PhoneBook phonebook;

	std::cout << "Welcome on the AwesomePhoneBook supported by AndroidAlpha" << std::endl;
	while (true)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT to use the AwesomePhoneBook" << std::endl;
		std::getline(std::cin, buff);
		if (std::cin.eof())
			return (EXIT_FAILURE);
		if (buff == "ADD")
			phonebook.add();
		if (buff == "SEARCH")
			phonebook.search();
		if (buff == "EXIT")
			phonebook.exit_phone();
	}
	std::cout << "Thank you, remember Android is the best" << std::endl;
	return (EXIT_SUCCESS);
}