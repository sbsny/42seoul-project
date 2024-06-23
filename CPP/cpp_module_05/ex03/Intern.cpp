
#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern() {}

Form	*Intern::makeShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

Form	*Intern::makeRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

Form	*Intern::makePresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeForm(std::string const &name, std::string const &target)
{
	Form	*(Intern::*f[3])(std::string const &target) = {
								&Intern::makeShrubberyCreationForm,
								&Intern::makeRobotomyRequestForm,
								&Intern::makePresidentialPardonForm};

	std::string	formNames[3] = {"shrubbery creation",
								"robotomy request",
								"presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*f[i])(target);
		}
	}
	throw Intern::UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "Intern: Unknown form";
}
