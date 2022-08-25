#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {

public:

	/*------Constructor and Destructor------*/
	Array(void) : _size(0), _array(new T[0]()) {}
	Array(unsigned int size) : _size(size), _array(new T[size]()) {}
	Array(const Array &original_array) : _size(original_array._size), _array(new T[_size]())
	{
		*this = original_array;
	}
	~Array(void)
	{
		delete [] _array;
	}

	/*---------------Overload---------------*/
	Array &operator=(const Array &arr)
	{
		unsigned int i = 0;

		if (_array != NULL)
			delete [] _array;
		_size = arr._size;
		_array = new T[_size];
		while (i < _size)
		{
			_array[i] = arr._array[i];
			i++;
		}
		return (*this);
	}

	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw(SegFault());
		else
			return (_array[i]);
	}

	/*--------------Exceptions--------------*/
	class SegFault : public std::exception {
		public :
			virtual const char *what() const throw() {
				return("\nBad index.\n");
		}
	};

	/*-----------Member functions-----------*/
	unsigned int size(void)
	{
		return (_size);
	}

private:

	unsigned int	_size;
	T				*_array;

};

#endif