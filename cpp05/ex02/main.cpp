#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("Grezette", 149);
	Bureaucrat b2("Zafod", 2);
	std::cout << "----Test exception too low----" << std::endl;
	try{
		std::cout << b1.getName() << " is the first bureaucrat with a grade of : " <<b1.getGrade() << std::endl;
		std::cout << b1 << std::endl;
		b1.decrGrade();
		std::cout << b1  << std::endl;
		b1.decrGrade();
		std::cout << b1  << std::endl;
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "----Test exception too high----" << std::endl;
	try{
		std::cout << b2.getName() << " is the second bureaucrat with a grade of : " <<b2.getGrade() << std::endl;
		std::cout << b2  << std::endl;
		b2.incrGrade();
		std::cout << b2  << std::endl;
		b2.incrGrade();
		std::cout << b2  << std::endl;
	} catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	{
		std::cout << std::endl << "----Test ShrubberyCreationForm form----" << std::endl;
		AForm *f1 = new ShrubberyCreationForm("home");
		std::cout << *f1 << std::endl;
		try{
			f1->execute(b1);
		} catch (std::exception & e){
			
		}
		b1.signForm(*f1);
		b2.signForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f1);
		delete f1;
	}
	{
		std::cout << std::endl << "----Test RobotomyRequestForm form----" << std::endl;
		AForm *f1 = new RobotomyRequestForm("elevator");
		std::cout << *f1 << std::endl;
		try{
			f1->execute(b1);
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		b1.signForm(*f1);
		b2.signForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f1);
		delete f1;
	}
	{
		std::cout << std::endl << "----Test PresidentialPardonForm form----" << std::endl;
		AForm *f1 = new PresidentialPardonForm("Grezette");
		std::cout << *f1 << std::endl;
		try{
			f1->execute(b1);
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		b1.signForm(*f1);
		b2.signForm(*f1);
		b2.signForm(*f1);
		b1.executeForm(*f1);
		b2.executeForm(*f1);
		std::cout << std::endl;
		delete f1;
	}
}