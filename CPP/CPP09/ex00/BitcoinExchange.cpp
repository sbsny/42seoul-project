#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	_database = rhs._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::parsing_data(std::string fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cout << "Error: data file can't be opened." << std::endl;
		exit(1);
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string	date = line.substr(0, line.find(','));
		float		value = atof(line.substr(line.find(',') + 1).c_str());

		_database[date] = value;
	}

	file.close();
}

void	BitcoinExchange::parsing_input(std::string fileName)
{
	std::ifstream	file(fileName.c_str());
	std::string		line;

	if (!file.is_open())
	{
		std::cout << "Error: input file can't be opened." << std::endl;
		exit(1);
	}

	while (std::getline(file, line))
	{
		if (line.find("date | value") == std::string::npos)
		{
			try
			{
				if (line.length() < 14 || line[4] != '-' || line[7] != '-' || line[11] != '|')
					throw std::runtime_error("Error: wrong format");

				std::string	date = line.substr(0, line.find('|') - 1);
				std::string	value_str = line.substr(line.find('|') + 2);
				float		value = atof(value_str.c_str());

				checking_data(date);
				checking_value(value_str, value);
				print_result(date, value);
			}
			catch(std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	file.close();
}

bool BitcoinExchange::if_leap(long year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}

void	BitcoinExchange::checking_data(std::string date)
{
	std::map<std::string, float>::iterator	it = _database.begin();

	for (unsigned long i = 0; i < date.length(); i++)
		if (!std::isdigit(date[i]) && date[i] != '-')
			throw std::runtime_error("Error: wrong date");

	int	year = atoi(date.substr(0, date.find('-')).c_str());
	int	month = atoi(date.substr(date.find('-') + 1, date.rfind('-')).c_str());
	int	day = atoi(date.substr(date.rfind('-') + 1).c_str());

	if (date < it->first || year < 2009
		|| month < 1 || month > 12 || day < 1 || day > 31)
		throw std::runtime_error("Error: wrong date");
	if (month == 2)
    {
        if (if_leap(year) && day > 29)
            throw std::runtime_error("Error: wrong date");
        if (!if_leap(year) && day > 28)
            throw std::runtime_error("Error: wrong date");
    }

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::runtime_error("Error: wrong date");
}

void	BitcoinExchange::checking_value(std::string value_str, float value)
{
	if (value < 0 || !value)
		throw std::runtime_error("Error: not a positive number.");
	if (value > 1000)
		throw std::runtime_error("Error: too large a number.");

	for (unsigned long i = 0; i < value_str.length(); i++)
		if (!std::isdigit(value_str[i]) && value_str[i] != '.')
			throw std::runtime_error("Error: wrong value");

	if (std::count(value_str.begin(), value_str.end(), '.') > 1)
		throw std::runtime_error("Error: wrong value");
}

void	BitcoinExchange::print_result(std::string date, float value)
{
	std::map<std::string, float>::iterator	it;
	it = _database.lower_bound(date);

	if (it->first != date)
		it--;

	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}
