#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input)
{
	_input = input;
	calculation();
}

RPN::RPN(const RPN &rhs)
{
	*this = rhs;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &rhs)
{
	_input = rhs._input;
	this->calculation();
	return (*this);
}

std::string removeSpaces(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

void	RPN::calculation()
{
	std::string removed = removeSpaces(_input);

	for (unsigned long i = 0; i < removed.length(); i++)
	{
		char c = removed[i];
		if (isdigit(c))
			_stack.push(static_cast<int>(c) - 48);
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error: Not enough numbers" << std::endl;
				exit(1);
			}
			first = _stack.top();
			_stack.pop();
			second = _stack.top();
			_stack.pop();
			switch (c)
			{
				case '*':
					_stack.push(second * first);
					break;
				case '/':
					if (first == 0)
					{
						std::cout << "Error: Can't be divided by zero" << std::endl;
						exit(1);
					}
					_stack.push(second / first);
					break;
				case '+':
					_stack.push(second + first);
					break;
				case '-':
					_stack.push(second - first);
					break;
			}
		}
		else
		{
			std::cout << "Error: Wrong character" << std::endl;
			exit(1);
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error: Stack remains" << std::endl;
		exit(1);
	}
	std::cout << _stack.top() << std::endl;
}
