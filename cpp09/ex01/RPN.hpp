#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

class OperandsumException : public std::runtime_error {
public:
	OperandsumException() : std::runtime_error("Error: not enough operands for + operator") {}
	virtual const char* what() const throw() {
		std::cerr << std::runtime_error::what() << std::endl;
		exit(128);
	}
};

class OperandsubException : public std::runtime_error {
public:
	OperandsubException() : std::runtime_error("Error: not enough operands for - operator") {}
	virtual const char* what() const throw() {
		std::cerr << std::runtime_error::what() << std::endl;
		exit(128);
	}
};

class OperandmulException : public std::runtime_error {
public:
	OperandmulException() : std::runtime_error("Error: not enough operands for * operator") {}
	virtual const char* what() const throw() {
		std::cerr << std::runtime_error::what() << std::endl;
		exit(128);
	}
};

class OperanddivException : public std::runtime_error {
public:
	OperanddivException() : std::runtime_error("Error: not enough operands for / operator") {}
	virtual const char* what() const throw() {
		std::cerr << std::runtime_error::what() << std::endl;
		exit(128);
	}
};

class DivideByZeroException : public std::runtime_error {
public:
	DivideByZeroException() : std::runtime_error("Error: division by zero") {}
	virtual const char* what() const throw() {
		std::cerr << std::runtime_error::what() << std::endl;
		exit(128);
	}
};

class RPN {
public:
	void add();
	void sub();
	void mul();
	void div();
	void push(int value);
	int result() const;
	bool empty() const;

private:
	std::stack<int> m_stack;
};

#endif
