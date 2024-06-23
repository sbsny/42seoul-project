#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac != 6)
	{
		std::cout << "Usage: " << "./file " << "[Bureaucrat name] "	<< "[Bureaucrat grade] "
		<< "[Form name] " << "[Grade to sign] "	<< "[Grade to execute]" << std::endl;

		return 0;
	}

	try
	{
		std::string	name = av[1];
		int			grade = atoi(av[2]);
		std::string	formName = av[3];
		int			gradeToSign = atoi(av[4]);
		int			gradeToExecute = atoi(av[5]);

		Bureaucrat	bureaucrat(name, grade);
		Form		form(formName, gradeToSign, gradeToExecute);

		std::cout << bureaucrat;
		std::cout << form;
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
