#include "RPN.hpp"

void RPN::add()
{
	if (m_stack.size() < 2)
		throw OperandsumException();
	int a = m_stack.top();
	m_stack.pop();
	int b = m_stack.top();
	m_stack.pop();
	m_stack.push(a + b);
}

void RPN::sub()
{
	if (m_stack.size() < 2)
		throw OperandsubException();
	int a = m_stack.top();
	m_stack.pop();
	int b = m_stack.top();
	m_stack.pop();
	m_stack.push(b - a);
}

void RPN::mul()
{
	if (m_stack.size() < 2)
		throw OperandmulException();
	int a = m_stack.top();
	m_stack.pop();
	int b = m_stack.top();
	m_stack.pop();
	m_stack.push(a * b);
}

void RPN::div()
{
	if (m_stack.size() < 2)
		throw OperanddivException();
	int a = m_stack.top();
	m_stack.pop();
	if (a == 0)
		throw DivideByZeroException();
	int b = m_stack.top();
	m_stack.pop();
	m_stack.push(b / a);
}

void RPN::push(int value)
{
	m_stack.push(value);
}

int RPN::result() const
{
	if (m_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return m_stack.top();
}

bool RPN::empty() const
{
	return m_stack.empty();
}
