#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	RPN	rpn(argv[1]);
	return 0;
}
