#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	btc;

	if (argc == 2)
	{
		btc.parsing_data("data.csv");
		btc.parsing_input(argv[1]);
	}
	else
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	return 0;
}
