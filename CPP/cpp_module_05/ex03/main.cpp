#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int	main(int ac, char **av)
{
	if (ac != 5)
	{
		std::cout << "Usage: " << "./file "	<< "[Bureaucrat name] "
		<< "[Bureaucrat grade] " << "[Target] " << "[Form name]" << std::endl;

		return 0;
	}

	try
	{
		std::string	bureaucratName = av[1];
		int			grade = atoi(av[2]);
		std::string	target = av[3];
		std::string	formName = av[4];

		Intern		intern;
		Bureaucrat	bureaucrat(bureaucratName, grade);
		Form		*form = intern.makeForm(formName, target);;
		std::cout << bureaucrat;
		std::cout << *form;
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);

		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
