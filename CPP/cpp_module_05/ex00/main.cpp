#include "Bureaucrat.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: " << "./file "	<< "[Bureaucrat name] "
		<< "[Bureaucrat grade]" << std::endl;

		return 0;
	}

	try
	{
		std::string	name = av[1];
		int			grade = atoi(av[2]);

		Bureaucrat	bureaucrat(name, grade);

		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
