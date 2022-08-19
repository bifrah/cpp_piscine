#include "Data.hpp"

int main()
{
	Data	data;

	data.c = 'b';
	data.nb = 2;
	data.str = "Hello world !";

	uintptr_t	serializ = serialize(&data);
	Data		deserializ = *deserialize(serializ);

	std::cout << "data : " << std::endl << data << std::endl << std::endl;
	std::cout << "serialize : " << std::endl << serializ << std::endl << std::endl;
	std::cout << "deserialize : " << std::endl << deserializ << std::endl;
}