#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

public:

	Span(unsigned int N);
	Span(const Span &span);
	~Span();

	Span&	operator=(const Span &span);

	unsigned int	getN(void) const ;

private:

	unsigned int	_N;
	std::vector<int> vect;
};

#endif