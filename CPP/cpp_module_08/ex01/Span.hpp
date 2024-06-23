#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span
{
	private:
		std::vector<int>	vec;
		unsigned int		n;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &copy);
		Span &operator=(Span const &rhs);
		~Span();

		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();

		class SpanFullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class SpanEmptyException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		// vector<int>::iterator
		template <typename Iter>
		void	addNumber(Iter begin, Iter end)
		{
			if (vec.size() + end - begin > n)
				throw SpanFullException();
			vec.insert(vec.begin(), begin, end);
		}
};

#endif
