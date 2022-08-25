#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>

template<typename T>
class MutantStack : public std::stack <T> {

public:
	/*----------Constructors and Destructor----------*/
	MutantStack(void) {}
	MutantStack(const MutantStack<T>& mutantStack) {
        *this = mutantStack;
    }
	~MutantStack() {}

	/*----------Overload----------*/
	MutantStack<T>& operator=(const MutantStack<T>& mutantStack) 
	{
        if (*this != mutantStack)
    		this->c = mutantStack.c;
        return (*this);
	}

	/*----------Iterators----------*/

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::reverse_iterator<iterator> reverse_iterator;
	typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

	iterator begin() {
		return (this->c.begin());
	}
	iterator end() {
		return (this->c.end());
	}

	const_iterator begin() const {
		return (this->c.begin());
	}
	const_iterator end() const {
		return (this->c.end());
	}

    reverse_iterator rbegin() {
		return (this->c.rbegin());
	}
    reverse_iterator rend() {
		return (this->c.rend());
	}

    const_reverse_iterator rbegin() const {
		return (this->c.rbegin());
	}
    const_reverse_iterator rend() const {
		return (this->c.rend());
	}

};

#endif