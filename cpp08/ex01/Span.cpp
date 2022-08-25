#include <Span.hpp>

/*----------Constructors and Destructor----------*/
Span::Span(unsigned int N) : _N(N) {
}

Span::Span(const Span &span) {
	*this = span;
}

Span::~Span() {
}

/*----------Overload----------*/
Span&	Span::operator=(const Span &span)
{
	if (this == &span)
		return (*this);
	this->_vect = span._vect;
	this->_N = span._N;
	return (*this);
	std::cout << "Span assignation copy constructor called" << std::endl;
}

/*----------Member Functions----------*/
void	Span::addNumber(unsigned int nb) {
	if (this->_vect.size() >= this->_N)
		throw (SpanIsFull());
	this->_vect.push_back(nb);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

unsigned int	Span::shortestSpan(void) {
	if (this->_vect.size() <= 1)
		throw (SpanIsNotHere());

	std::sort(this->_vect.begin(), this->_vect.end());

	std::vector<int>::iterator	it = this->_vect.begin();
	std::vector<int>::iterator	it_plus_one;
	unsigned int	distance = *(this->_vect.end() - 1) - *(this->_vect.begin());
	unsigned int	tmp;
	
	while (it != this->_vect.end() - 1)
	{
		it_plus_one = it + 1;
		tmp = *it_plus_one - *it;
		if (tmp < distance)
			distance = tmp;
		it++;
	}
	return (distance);
	// on check si le couple precedent est encore plus petit... etc
	// on stocke dans tmp a chaque fois pour compare la distance actuelle a tmp
	// on retourne le plus petit nombre
}
