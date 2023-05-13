#include "RPN.hpp"

RPN::~RPN() {
	while (!m_stack.empty())
		m_stack.pop();
}

void RPN::add()
{
	if (m_stack.size() < 2)
		throw OperandsumException();
	float a = m_stack.top();
	m_stack.pop();
	float b = m_stack.top();
	m_stack.pop();
	m_stack.push(a + b);
}

void RPN::sub()
{
	if (m_stack.size() < 2)
		throw OperandsubException();
	float a = m_stack.top();
	m_stack.pop();
	float b = m_stack.top();
	m_stack.pop();
	m_stack.push(b - a);
}

void RPN::mul()
{
	if (m_stack.size() < 2)
		throw OperandmulException();
	float a = m_stack.top();
	m_stack.pop();
	float b = m_stack.top();
	m_stack.pop();
	m_stack.push(a * b);
}

void RPN::div()
{
	if (m_stack.size() < 2)
		throw OperanddivException();
	float a = m_stack.top();
	m_stack.pop();
	if (a == 0)
		throw DivideByZeroException();
	float b = m_stack.top();
	m_stack.pop();
	m_stack.push(b / a);
}

void RPN::push(float value)
{
	m_stack.push(value);
}

float RPN::result() const
{
	if (m_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	return m_stack.top();
}

bool RPN::empty() const
{
	return m_stack.empty();
}
