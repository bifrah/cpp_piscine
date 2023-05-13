#include "RPN.hpp"

int main(int argc, char** argv) {
	RPN calc;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		std::string token;
		while (getline(ss, token, ' '))
		{
			if (!token.empty())
			{
				if (token == "+")
					calc.add();
				else if (token == "-")
					calc.sub();
				else if (token == "*")
					calc.mul();
				else if (token == "/")
					calc.div();
				else 
					calc.push(atof(token.c_str()));
			}
		}
	}
	try {
		std::cout << calc.result() << std::endl;
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return (1);
	}
	return 0;
}
