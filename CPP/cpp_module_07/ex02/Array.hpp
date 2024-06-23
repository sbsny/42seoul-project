#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*array;
		unsigned int	len;

	public:
		Array() : array(new T[0]), len(0)
		{
		}

		Array(unsigned int n) : array(new T[n]), len(n)
		{
		}

		Array(Array const &copy)
		{
			len = copy.len;
			array = new T[len];
			for (unsigned int i = 0; i < len; i++)
				array[i] = copy.array[i];
		}

		~Array()
		{
			delete [] array;
		}

		Array	&operator=(Array const &rhs)
		{
			if (this == rhs)
				return *this;
			delete [] array;
			len = rhs.len;
			array = new T[len];
			for (unsigned int i = 0; i < rhs.len; i++)
				array[i] = rhs.array[i];
			return *this;
		}

		T	&operator[](unsigned int i)
		{
			if (i >= len)
				throw std::exception();
			return array[i];
		}

		T const	&operator[](unsigned int i) const
		{
			if (i >= len)
				throw std::exception();
			return array[i];
		}

		unsigned int	size() const
		{
			return len;
		}
};

template <typename T>
void	printArray(T &a, std::string name)
{
	std::cout << name << " : ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

#endif
