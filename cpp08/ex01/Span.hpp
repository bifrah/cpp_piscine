#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

template <typename T>
class Span {

public:

	Span::Span(unsigned int N) : _N(N)
	{
		std::cout << "Span default constructor called." << std::endl;
	}

	Span::Span(const Span &span) 
	{
		*this = span;
		std::cout << "Span copy constructor called." << std::endl;
	}

	Span::~Span()
	{
		std::cout << "Span destructor called." << std::endl;
	}

	Span&	operator=(const Span &span)
	{
		if (this == &span)
			return (*this);
		this->_N = span.getN();
		return (*this);
		std::cout << "Span assignation copy constructor called" << std::endl;
	}

	unsigned int	getN(void) const
	{
		return (this->_N);
	}

private:

	unsigned int	_N;
	std::vector<int> vect;
};

#endif