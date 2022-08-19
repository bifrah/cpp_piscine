#include "Bureaucrat.hpp"

int main()
{
	std::cout << "----------Basic Test----------" << std::endl;
	try {
		Bureaucrat b("Jean", 420);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;

	std::cout << std::endl << "--------High grade test--------" << std::endl;
	try {
		Bureaucrat worker1("Ginette", 2);
		std::cout << worker1  << std::endl;
		worker1.incrGrade();
		std::cout << worker1  << std::endl;
		worker1.incrGrade();
		std::cout << worker1  << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;


	std::cout << std::endl << "---------Low grade test---------" << std::endl;
	try {
		Bureaucrat worker2("Jeanine", 149);
		std::cout << worker2 << std::endl;
		worker2.decrGrade();
		std::cout << worker2  << std::endl;
		worker2.decrGrade();
		std::cout << worker2  << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
	std::cout << std::endl << "-----Copy assignation test-----" << std::endl;
	try {
		Bureaucrat worker3("J-J Goldman", 42);
		Bureaucrat worker4("J-J Silverman ", 21);
		std::cout << worker3  << std::endl;
		std::cout << worker4  << std::endl;
		worker4 = worker3;
		std::cout << worker3  << std::endl;
		std::cout << worker4  << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------" << std::endl;
}