#include <Span.hpp>

int	main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{	Span	sp_me1(5);

		sp_me1.addNumber(21);
		sp_me1.addNumber(3);
		sp_me1.addNumber(12);
		sp_me1.addNumber(15);
		sp_me1.addNumber(2);

		//			{21		3		12		15		2}
		// diff :		18		9	 	3		13
		// sort ->	{2		3		12		15		21}
		// diff :		1		9	 	3		6

		std::cout << "-----ShortestSpan Test-----" << std::endl;
		std::cout << "-> " << sp_me1.shortestSpan() << std::endl; // should return 3 - 2 = 1


		std::cout << "-----LongestSpan Test-----" << std::endl;
		std::cout << "-> " << sp_me1.longestSpan() << std::endl; // should return 21 - 2 = 19
	}
	{
		Span	sp_me2(10000);

		std::vector<int>::iterator i;
		std::vector<int>::iterator it;
		std::vector<int> vect(10042, 21);
		try	{
			sp_me2.addNumbers(vect.begin(), vect.end());
			sp_me2.print();
		}
		catch(const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		
	}
}
