#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_input = NULL;
}

BitcoinExchange::BitcoinExchange(std::ifstream *input, myMap *data_map)
{
	_input = input;
	_data_map = data_map;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc)
{
	*this = btc;
}

BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc)
{
	this->_input = btc._input;
	this->_data_map = btc._data_map;
	return (*this);
}

int	BitcoinExchange::error_message(std::string str)
{
	std::cout << str << std::endl;
	return 0;
}

int BitcoinExchange::check_date(std::string &date_str)
{
	struct tm	date;
	time_t		t;
	date_t		d;

	d.year = std::atoi(date_str.substr(0, 4).c_str()) - 1900;
	d.month = std::atoi(date_str.substr(5, 2).c_str()) - 1;
	d.day = std::atoi(date_str.substr(8, 2).c_str());

	std::memset(&date, 0, sizeof(date));
	date.tm_year = d.year;
	date.tm_mon = d.month;
	date.tm_mday = d.day;
	t = std::mktime(&date);

    if (t == -1 || date.tm_year != d.year || date.tm_mon != d.month || date.tm_mday != d.day)
        return 0;

    return 1;
}

int BitcoinExchange::check_line(std::string line)
{
	_date = line.substr(0, 10);
	if (line.length() < 14 || line[4] != '-' || line[7] != '-' || !check_date(_date))
		return (error_message("Error: bad input => " + line));
	_value = std::atof(line.substr(13).c_str());
	if (_value < 0 || !_value)
		return (error_message("Error: not a positive number."));
	if (_value > 1000)
		return (error_message("Error: too large a number."));
	return (1);
}

int BitcoinExchange::converter()
{
	std::string		line;
	myMap::iterator	it;

	std::getline(*_input, line);
	while (std::getline(*_input, line))
	{
		if (!check_line(line))
			continue;
		it = _data_map->upper_bound(line.substr(0, 10));
		--it;
		std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;
	}
	return 0;
}
