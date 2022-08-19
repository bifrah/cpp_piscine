#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>

Base*	generate(void)
{
	srand(time(NULL));
	Base*	generated = NULL;
	int		nb = rand() % 3;

	if (nb == 0)
	{
		generated = new A();
		std::cout << "Instance A created." << std::endl;
	}

	if (nb == 1)
	{
		generated = new B();
		std::cout << "Instance B created." << std::endl;
	}

	if (nb == 2)
	{
		generated = new C();
		std::cout << "Instance C created." << std::endl;
	}
	return (generated);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "It's an instance of A." << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "It's an instance of B." << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "It's an instance of C." << std::endl;
}

void	identify(Base& p)
{
	try {
		A data = dynamic_cast<A &>(p);
		std::cout << "It's an instance of A." << std::endl;
	}
	catch(std::exception &e) {
	}
	try {
		B data = dynamic_cast<B &>(p);
		std::cout << "It's an instance of B." << std::endl;
	}
	catch(std::exception &e) {
	}
	try {
		C data = dynamic_cast<C &>(p);
		std::cout << "It's an instance of C." << std::endl;
	}
	catch(std::exception &e) {
	}
}

int		main()
{
	Base	*find_me = generate();
	
	identify(find_me);
	identify(*find_me);
	delete (find_me);
	return (0);
}