#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <fstream>
# include <map>
# include <ctime>
# include <cstring>
# include <cstdlib>

typedef struct date_s
{
	int	year;
	int	month;
	int	day;
} date_t;

typedef std::map<std::string, float> myMap;

class BitcoinExchange
{
	private:
		std::string		_date;
		double			_value;
		std::ifstream	*_input;
		myMap			*_data_map;
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream *input, myMap *data_map);
		BitcoinExchange(const BitcoinExchange &btc);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &btc);

		int		converter();
		int		check_line(std::string line);
		int		check_date(std::string &date_str);
		int		error_message(std::string str);
};

#endif
