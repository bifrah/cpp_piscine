#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) \
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm) \
: AForm("ShrubberyCreationForm", 145, 137)
{
	*this = shrubberyCreationForm;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator= (const ShrubberyCreationForm &SCform)
{
	if (this == &SCform)
		return (*this);
	std::cout << "ShrubberyCreationForm assignation copy constructor called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::_print_tree(void) const
{
	std::string	out_file;
	
	out_file = _target;
	out_file += "_shrubbery";

	std::ofstream	of_stream(out_file.c_str());

	if (of_stream)
	{
		of_stream << "                  __..-----')											" << std::endl;
		of_stream << "        ,.--._ .-'_..--...-'											" << std::endl;
		of_stream << "       '-''. _/_ /  ..--''''-.										" << std::endl;
		of_stream << "       _.--''...:._:(_ ..:'::. \\										" << std::endl;
		of_stream << "    .-' ..::--''_(##)#)'':. \\ \\)    \\ _|_ /							" << std::endl;
		of_stream << "   /_:-:'/  :__(##)##)    ): )   '-./'   '\\.-'						" << std::endl;
		of_stream << "   '  / |  :' :/''\\///)  /:.'    --(       )--						" << std::endl;
		of_stream << "     / :( :( :(   (#//)  '       .-'\\.___./'-.						" << std::endl;
		of_stream << "    / :/|\\ :\\_:\\   \\#//\\            /  |  \\							" << std::endl;
		of_stream << "    |:/ | ''--':\\   (#//)              '								" << std::endl;
		of_stream << "    \\/  \\ :|  \\ :\\  (#//)												" << std::endl;
		of_stream << "         \\:\\   '.':. \\#//\\											" << std::endl;
		of_stream << "          ':|    '--'(#///)											" << std::endl;
		of_stream << "                     (#///)											" << std::endl;
		of_stream << "                     (#///)     	 									" << std::endl;
		of_stream << "                      \\#///\\											" << std::endl;
		of_stream << "                      (##///)         								" << std::endl;
		of_stream << "                      (##///)         								" << std::endl;
		of_stream << "                      (##///)         								" << std::endl;
		of_stream << "                      (##///)        									" << std::endl;
		of_stream << "                       \\##///\\        								" << std::endl;
		of_stream << "                       (###///)       								" << std::endl;
		of_stream << "                       (###////)__...--:: :...__						" << std::endl;
		of_stream << "                       (#/::'''                  ''--.._				" << std::endl;
		of_stream << "                  __..-'''                             '-._			" << std::endl;
		of_stream << "          __..--''                                       '._			" << std::endl;
		of_stream << " ___..--''                                                   '-..___	" << std::endl;
		of_stream << "   (_ ''---....___                                     __...--'' _)	" << std::endl;
		of_stream << "     '''--...  ___'''''-----......._______......----'''     --'''		" << std::endl;
		of_stream << "                   ''''       ---.....   ___....----					" << std::endl;
	}
	else
		std::cerr << "Impossible to create new_file." << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
	{
		throw AForm::NotSigned();
	}
	if (executor.getGrade() > this->getGradeToExec())
	{
		throw AForm::GradeTooLowException();
	}
	_print_tree();
}