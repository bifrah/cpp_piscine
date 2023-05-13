#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

class OperandsumException : public std::exception {
public:
    OperandsumException() : std::exception() {}
    virtual const char* what() const throw() {
        return ("Error: not enough operands for + operator");
    }
};

class OperandsubException : public std::exception  {
public:
	OperandsubException() : std::exception() {}
	virtual const char* what() const throw() {
		return ("Error: not enough operands for - operator");
	}
};

class OperandmulException : public std::exception  {
public:
	OperandmulException() : std::exception() {}
	virtual const char* what() const throw() {
		return ("Error: not enough operands for * operator");
	}
};

class OperanddivException : public std::exception  {
public:
	OperanddivException() : std::exception() {}
	virtual const char* what() const throw() {
		return ("Error: not enough operands for / operator");
	}
};

class DivideByZeroException : public std::exception  {
public:
	DivideByZeroException() : std::exception() {}
	virtual const char* what() const throw() {
		return ("Error: division by zero");
	}
};

class RPN {
public:
	~RPN();

	void add();
	void sub();
	void mul();
	void div();
	void push(float value);
	float result() const;
	bool empty() const;

private:
	std::stack<float> m_stack;
};

#endif
