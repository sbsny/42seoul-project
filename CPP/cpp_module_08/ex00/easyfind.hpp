#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		const char	*what() const throw()
		{
			return "Element not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &ToSearch, int value)
{
	typename T::iterator res;

	res = std::find(ToSearch.begin(), ToSearch.end(), value);
	if (res == ToSearch.end())
	{
		throw NotFoundException();
	}

	return (res);
};

#endif
