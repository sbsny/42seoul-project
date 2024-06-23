#include "BitcoinExchange.hpp"

int	error_print2(std::string str)
{
	std::cout << str << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	std::string		line;
	std::ifstream	input;
	std::ifstream	data;
	myMap			data_map;

	if (argc != 2)
		return (error_print2( "Error"));
	input.open(argv[1], std::ifstream::in);
	data.open("./data.csv", std::ifstream::in);
	if (!data)
		return (error_print2("Error: Data file can't be opened."));
	if (!input)
		return (error_print2("Error: Input file can't be opened."));
	std::getline(data, line);
	while (std::getline(data, line))
		data_map[line.substr(0, 10)] = atof(line.substr(11).c_str());

	BitcoinExchange	btc(&input, &data_map);
	btc.converter();

	input.close();
	data.close();

	return 0;
}
