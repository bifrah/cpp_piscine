#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

int add(std::stack<int>& st)
{
	if (st.size() < 2)
	{
		std::cerr << "Error: not enough operands for + operator" << std::endl;
		exit(128);
	}
	int a = st.top();
	st.pop();
	int b = st.top();
	st.pop();
	st.push(a + b);
	return st.top();
}

int sub(std::stack<int>& st)
{
	if (st.size() < 2)
	{
		std::cerr << "Error: not enough operands for - operator" << std::endl;
		exit (128);
	}
	int a = st.top();
	st.pop();
	int b = st.top();
	st.pop();
	st.push(b - a);
	return st.top();
}

int mul(std::stack<int>& st)
{
	int a = st.top();
	if (st.size() < 2)
	{
		std::cerr << "Error: not enough operands for * operator" << std::endl;
		exit (128);
	}
	st.pop();
	int b = st.top();
	st.pop();
	st.push(a * b);
	return st.top();
}

int div(std::stack<int>& st)
{
	if (st.size() < 2)
	{
		std::cerr << "Error: not enough operands for / operator" << std::endl;
		exit (128);
	}
	int a = st.top();
	st.pop();
	if (a == 0)
	{
		std::cerr << "Error : division by zero" << std::endl;
		exit (128);
	}
	int b = st.top();
	st.pop();
	st.push(b / a);
	return st.top();
}


int main(int argc, char** argv) {
	std::stack<int> st;
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		std::string token;
		while (getline(ss, token, ' '))
		{
			if (token == "+")
				add(st);
			else if (token == "-")
				sub(st);
			else if (token == "*")
				mul(st);
			else if (token == "/")
				div(st);
			else 
				st.push(atoi(token.c_str()));
		}
	}
	std::cout << st.top() << std::endl;
	return 0;
}