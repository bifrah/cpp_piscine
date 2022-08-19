#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {

	std::cout << "PhoneBook constructor called" << std::endl;
	this->index = 0;
	return;
}


PhoneBook::~PhoneBook(void) {

	std::cout << "PhoneBook destructor called" << std::endl;
	return;
}

void	PhoneBook::add() {

	int	i = 0;

	if (this->index < 8)
	{
		this->repertory[this->index].SetContact(this->index);
		this->index++;
	}
	else
	{
		repertory[i].~Contact();
		while (i < 7)
		{
			repertory[i] = repertory[i + 1];
			repertory[i].ChangeIndex();
			i++;
		}
		repertory[i].SetContact(i);
	}
	return;
}

int		PhoneBook::_ft_atoi(std::string str) const {

	int	i;
	int	result;
	int	score;

	i = 0;
	result = 0;
	score = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			score = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (score * result);
}

int		PhoneBook::_ft_isdigit(std::string str) const {

	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (0);
	while (str[i] == '+')
		i++;
	while (std::isdigit(str[i]))
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


void	PhoneBook::_Trunc_and_Print_str(std::string str) {

	if (str.size() > 10)
	{
		str[9] = '.';
		std::cout << std::setfill(' ') << std::setw(10) << str.substr(0, 10);
	}
	else
		std::cout << std::setfill(' ') << std::setw(10) << str;
}

void	PhoneBook::_PrintTruncContact(Contact &contact) {

	std::cout << "<         ";
	contact.ShowIndex();
	std::cout << " | ";
	_Trunc_and_Print_str(contact.ReturnFirstname());
	std::cout << " | ";
	_Trunc_and_Print_str(contact.ReturnLastname());
	std::cout << " | ";
	_Trunc_and_Print_str(contact.ReturnNickname());
	std::cout << " >";
	std::cout << std::endl;
}

void	PhoneBook::search(void) {

	int			i = 0;
	std::string	buff;
	
	if (this->index == 0)
		std::cout << "Your repertory is empty" << std::endl;
	else
	{
		std::cout << "<     Index |  Firstname |   Lastname |   Nickname >" << std::endl;
		while (i < this->index)
		{
			_PrintTruncContact(repertory[i]);
			i++;
		}
	}
	std::cout << "Which contact do you want? Enter the index." << std::endl;
	std::getline(std::cin, buff);
	if (std::cin.eof())
            return ;
	while (buff.size() > 1 || buff[0] >= PhoneBook::index + 48 || !_ft_isdigit(buff))
	{
		std::cout << "Wrong index, please retry." << std::endl;
		std::getline(std::cin, buff);
		if (std::cin.eof())
            return ;
		if (buff.size() == 1 && _ft_isdigit(buff) && buff[0] < PhoneBook::index + 48)
			break ;
	}
	this->repertory[_ft_atoi(buff)].ShowContact();
	return;
}

void	PhoneBook::exit_phone(void) {

	exit(0);
}
