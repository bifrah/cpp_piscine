#include <cstdlib>
#include <cctype>
#include <iostream>
#include <cmath>

void	convert_char(double data)
{
	char c = static_cast<char>(data);
	if (std::isnan(data) || std::isinf(data))
		std::cout << "Char : Imposible." << std::endl;
	else if (!std::isprint(c))
		std::cout << "Char : Non displayable." << std::endl;
	else
		std::cout << "Char : " << static_cast<char>(data) << std::endl;
}

void	convert_int(double data)
{
	int i = static_cast<int>(data);
	if (std::isnan(data) || std::isinf(data))
		std::cout << "Int : Imposible." << std::endl;
	else
		std::cout << "Int : " << i << std::endl;
}

void	convert_float(double data, std::string str)
{
	float f = static_cast<float>(data);
	if ((std::isnan(data) || std::isinf(data)) && (!str.compare("nan") && !str.compare("nanf")))
		std::cout << "Float : Imposible." << std::endl;
	if ((((str.compare("nan") == 0 || str.compare("nanf") == 0) || std::isinf(data))
		|| (str.find('.') != std::string::npos)) && str.find(".0\0") == std::string::npos)
		std::cout << "Float : " << f << "f" << std::endl;
	else
		std::cout << "Float : " << f << ".0f" << std::endl;
}

void	convert_double(double data, std::string str)
{
	std::cout << "Double : " << static_cast<double>(data);
	if (str.compare("nan") && str.compare("nanf") && !std::isinf(data)
		&& ((str.find('.') == std::string::npos) || str.find(".0\0") != std::string::npos))
		std::cout << ".0";
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	double	data;

	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments." << std::endl;
		return (1);
	}
	if (std::isprint(argv[1][0]) && !argv[1][1] && !std::isdigit(argv[1][0]))
		data = static_cast<double>(argv[1][0]);
	else
		data = std::atof(argv[1]);
	convert_char(data);
	convert_int(data);
	convert_float(data, argv[1]);
	convert_double(data, argv[1]);
}