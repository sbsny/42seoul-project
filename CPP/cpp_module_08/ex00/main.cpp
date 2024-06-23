#include "easyfind.hpp"

int	main()
{
	std::vector<int> vector;
	std::deque<int> deque;

	vector.push_back(5);
	vector.push_back(7);
	vector.push_back(42);

	deque.push_back(5);
	deque.push_back(7);
	deque.push_back(42);

	try
	{
		std::cout << "======= vector =======" << std::endl;
		std::cout << *easyfind(vector, 5) << std::endl;
		std::cout << *easyfind(vector, 7) << std::endl;
		std::cout << *easyfind(vector, 10) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "======= deque =======" << std::endl;
		std::cout << *easyfind(deque, 5) << std::endl;
		std::cout << *easyfind(deque, 7) << std::endl;
		std::cout << *easyfind(deque, 10) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
