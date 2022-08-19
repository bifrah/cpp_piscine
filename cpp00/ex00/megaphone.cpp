#include <iostream>
#include <string>
#include <cstdlib>

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	std::string	tmp;

	j = 1;
	i = -1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		while (j < argc)
		{
			tmp += argv[j];
			j++;
		}
		while (tmp[++i])
			tmp[i] = std::toupper(tmp[i]);
		std::cout << tmp << std::endl;
	}
	return (EXIT_SUCCESS);
}