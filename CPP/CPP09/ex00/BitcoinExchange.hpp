#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_database;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &rhs);
		~BitcoinExchange();

		void	parsing_data(std::string fileName);
		void	parsing_input(std::string fileName);
		void	checking_data(std::string date);
		void	checking_value(std::string value_str, float value);
		void	print_result(std::string date, float value);
		bool 	if_leap(long year);
};

#endif
