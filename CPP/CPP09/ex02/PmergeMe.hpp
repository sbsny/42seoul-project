#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <iterator>
# include <algorithm>

class PmergeMe
{
	private:
		std::deque<int>		_deq;
		std::vector<int>	_vec;
	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &rhs);

		int		digit_check(std::string str);
		void	print_first(std::string str);
		void	sort_print();
};

template <typename T>
void	insertion_sort(T &container)
{
	typename T::iterator it = container.begin();
	typename T::iterator it2;

	while (it != container.end())
	{
		it2 = it;
		while (it2 != container.begin() && *it2 < *(it2 - 1)) {
			std::iter_swap(it2, it2 - 1);
			it2--;
		}
		it++;
	}
}

template <typename T>
void	merge_sort(T &container)
{
	if (container.size() <= 10)
	{
		insertion_sort(container);
		return ;
	}
	typename T::iterator mid = container.begin() + container.size() / 2;
	T left(container.begin(), mid);
	T right(mid, container.end());
	merge_sort(left);
	merge_sort(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
}

#endif
