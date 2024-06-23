#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	PmergeMe	merge(argv);
	return 0;
}
