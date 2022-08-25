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
	{	Span	sp(5);

		sp.addNumber(21);
		sp.addNumber(3);
		sp.addNumber(12);
		sp.addNumber(15);
		sp.addNumber(2);

		//			{21		3		12		15		2}
		// diff :		18		9	 	3		13
		// sort ->	{2		3		12		15		21}
		// diff :		1		9	 	3		6

		std::cout << "-----ShortestSpan Test-----" << std::endl;
		std::cout << "-> " << sp.shortestSpan() << std::endl;


		std::cout << "-----LongestSpan Test-----" << std::endl;
		std::cout << "-> " << sp.longestSpan() << std::endl;
	}
}
