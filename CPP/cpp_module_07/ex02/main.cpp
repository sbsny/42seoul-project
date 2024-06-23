#include "Array.hpp"

int	main()
{
	Array<int> a(5);
	srand(time(NULL));

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i + rand() % 10;

	Array<int> b(a);

	printArray(a, "a");
	printArray(b, "b");
	std::cout << std::endl;

	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i;

	printArray(a, "a");
	printArray(b, "b");
	std::cout << std::endl;

	const Array<int>	c(5);
	std::cout << c[0] << std::endl;

	try
	{
		a[6] = 42;
		std::cout << a[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Index is out of range" << std::endl;
	}

	try
	{
		b[-5] = 42;
		std::cout << b[-5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Index is out of range" << std::endl;
	}

	return 0;
}
