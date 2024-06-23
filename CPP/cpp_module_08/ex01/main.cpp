#include "Span.hpp"

int main()
{
	try
	{
		Span	sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span				sp2 = Span(10000);
		std::vector<int>	v2;

		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
			v2.push_back(rand());

		sp2.addNumber(v2.begin(), v2.end());

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
