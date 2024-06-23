#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	int	i = 1;
	while (argv[i] && digit_check(argv[i]))
	{
		_deq.push_back(atoi(argv[i]));
        _vec.push_back(atoi(argv[i]));
		i++;
	}
	sort_print();
}

PmergeMe::PmergeMe(const PmergeMe &rhs) {
	*this = rhs;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	std::copy(rhs._vec.begin(), rhs._vec.end(), _vec.begin());
	std::copy(rhs._deq.begin(), rhs._deq.end(), _deq.begin());
	sort_print();
	return (*this);
}

int	PmergeMe::digit_check(std::string str)
{
	for (unsigned long i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
	}
	return 1;
}

void	PmergeMe::print_first(std::string str)
{
	std::deque<int>::iterator it = _deq.begin();
	std::cout << str << ": ";
	while (it != _deq.end() && std::distance(_deq.begin(), it) < 4)
		std::cout << *it++ << " ";
	if (_deq.size() == 5)
		std::cout << *it;
	else if (_deq.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	PmergeMe::sort_print()
{
	clock_t	start;
	clock_t	end;
	double	elapsed;

	print_first("Before sort");

	start = clock();
	merge_sort(_deq);
	_deq.assign(_deq.begin(), std::unique(_deq.begin(), _deq.end()));
	end = clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC;
	print_first("After sort");
	std::cout << "Time to process with std::deque: " << elapsed * 1000000 << " microseconds" << std::endl;

	start = clock();
	merge_sort(_vec);
	_vec.assign(_vec.begin(), std::unique(_vec.begin(), _vec.end()));
	end = clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process with std::vector: " << elapsed * 1000000 << " microseconds" << std::endl;
;
}
