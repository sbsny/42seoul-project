#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class RPN
{
	private:
		int				first;
		int				second;
		std::string		_input;
		std::stack<int>	_stack;

	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &rhs);
		~RPN();
		RPN	&operator=(const RPN &rhs);

		void	calculation();
};

#endif
