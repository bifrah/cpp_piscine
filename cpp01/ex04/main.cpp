#include "noSed.hpp"


void	ft_replace(std::string &str, std::string occ1, std::string occ2)
{
	int	i = 0;

	while ((i = str.find(occ1)) != -1)
	{
		str.erase(i, occ1.size());
		str.insert(i, occ2);
	}
}

int	main(int argc, char **argv) {

	if (argc != 4)
	{
		std::cout << "Please run it like that : \"a.out filename str1 str2\"" << std::endl;
		return (1);
	}
	std::string	occ1 = argv[2];
	std::string	occ2 = argv[3];
	if (occ1.compare(occ2) == 0 || occ2.compare(occ1) == 0)
	{
		std::cout << "Your words are the same." << std::endl;
		return (0);
	}
	if (occ1.find(occ2) == 1)
	{
		std::cout << "Don't troll me please. Do you want an infinite loop ?" << std::endl;
		return (0);
	}
	std::ifstream	if_stream(argv[1]);
	std::string		buff;

	std::string		namefile;
	namefile = argv[1];
	namefile += ".replace";

	std::ofstream	of_stream(namefile.c_str());

	if(of_stream && if_stream)
	{
		while (getline(if_stream, buff))
		{
			ft_replace(buff, argv[2], argv[3]);
			of_stream << buff << std::endl;
			if (if_stream.eof() == true)
				return (0);
		}
	}
	else
		std::cout << "ERROR: use real path or check your rights please." << std::endl;
	return (0);
}
