#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

template <typename T>
class Span {

public:

/*----------Exceptions----------*/
	class SpanIsFull : public std::exception {
		public :
			const char*	SpanIsFull::what() const throw() {
				return ("Span is full.");
			}
			virtual const char* what() throw()
	}

	class SpanIsNotHere : public std::exception {
		public :
			const char*	SpanIsNotHere::what() const throw() {
				return ("Span doesn't exist.");
			}
			virtual const char* what() throw()
	}

/*----------Constructors and Destructor----------*/
	Span::Span(unsigned int N) : _N(N) {
	}

	Span::Span(const Span &span) {
		*this = span;
	}

	Span::~Span() {
	}

/*----------Overload----------*/
	Span&	operator=(const Span &span)
	{
		if (this == &span)
			return (*this);
		this->_vect = span._vect;
		this->_N = span._N;
		return (*this);
		std::cout << "Span assignation copy constructor called" << std::endl;
	}

/*----------Member Functions----------*/
	void	addNumber(int nb) {
		if (this->_vect.size() >= this->_N)
			throw (SpanIsFull());
		this->_vect.push_back(nb);
	}

	void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
		while (begin != end)
		{
			addNumber(*begin);
			begin++;
		}
	}

	void	shortestSpan() {
		int	distance;
		int	tmp;
		
		if (this->_vect.size() <= 1)
			throw (SpanIsNotHere());
		std::sort(this->_vect.begin(), this->_vect.end())
		// distance = vect.end - vect.end - 1
		// on check si le couple precedent est encore plus petit... etc
		// on stocke dans tmp a chaque fois pour compare la distance actuelle a tmp
		// on retourne le plus petit nombre
	}

private:

	std::vector<int>	_vect;
	unsigned int		_N;
};

#endif