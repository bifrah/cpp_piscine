#include "Array.hpp"
#include <cstring>


template <typename T>
void print_array(T &array, unsigned int size)
{
	unsigned int i = 0;

	while (i < size)
	{
		try
		{
			std::cout << array[i] << " ";
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << " ";
		}
		i++;
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "\n----------Test with empty array : ----------" << std::endl;
	Array <int>test0(void);

	std::cout << "\n----------Test with int : ------------------" << std::endl;
	Array <int>test(42);

	std::cout << "\n----------Default values : -----------------" << std::endl;
	print_array(test, 42);

	std::cout << "\n----------Set values : ---------------------" << std::endl;
	test[2] = -42;
	test[21] = 42;
	print_array(test, 42);

	std::cout << "\n----------Access beyond bounds : -----------" << std::endl;
	try
	{
		std::cout << test[45];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		test[43] = 999;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	print_array(test, 45);

	std::cout << "\n----------Copy test 1 : --------------------" << std::endl;
	Array <int>test2(3);
	test2 = test;
	print_array(test2, 42);

	std::cout << "\n----------Copy test 2 : --------------------" << std::endl;
	Array <int>test3(test2);
	print_array(test3, 42);

	std::cout << "\n----------Test with std::string : ----------" << std::endl;
	Array <std::string>test4(42);
	try
	{
		test4[2] = "HELLO";
		test4[21] = "WORLD";
		test4[42] = "ERROR";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	print_array(test4, 42);
}