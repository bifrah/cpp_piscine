#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {

public:

	/*----------Exceptions----------*/
	class SpanIsFull : public std::exception {
		public :
			const char*	what() const throw() {
				return ("Span is full.");
			}
	};
	class SpanIsNotHere : public std::exception {
		public :
			const char*	what() const throw() {
				return ("Span doesn't exist.");
			}
	};

	/*----------Constructors and Destructor----------*/
		Span(unsigned int N);
		Span(const Span &span);
		~Span();

	/*----------Overload----------*/
		Span&			operator=(const Span &span);

	/*----------Member Functions----------*/
		void			addNumber(unsigned int nb);
		void			addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
	
		void			print(void);

private:

	std::vector<int>	_vect;
	unsigned int		_N;
};

#endif