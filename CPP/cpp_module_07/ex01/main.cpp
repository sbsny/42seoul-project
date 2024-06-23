#include "iter.hpp"

int	main()
{
	std::cout << "========== TEST1 ==========" << std::endl;
	int array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print);

	std::cout << "========== TEST2 ==========" << std::endl;
	double	array3[] = {0.0, 0.1, 0.2, 0.3, 0.4};
	iter(array3, 5, print);

	std::cout << "========== TEST3 ==========" << std::endl;
	std::string	array2[] = {"test1", "test2", "test3"};
	iter(array2, 3, print);

	return 0;
}
