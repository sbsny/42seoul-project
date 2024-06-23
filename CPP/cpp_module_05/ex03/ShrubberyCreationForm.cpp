#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form("ShrubberyCreationForm", 145, 137),
	_target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreationForm", 145, 137),
	_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) :
	Form(copy),
	_target(copy._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	Form::operator=(rhs);
	this->_target = rhs._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	file;

	file.open(this->_target + "_shrubbery");
	if (!file.is_open())
		throw ShrubberyCreationForm::OpenException();

	file << "                  _-_                     " << std::endl;
	file << "               /~~   ~~\\                  " << std::endl;
	file << "            /~~         ~~\\               " << std::endl;
	file << "           {               }              " << std::endl;
	file << "            \\  _-     -_  /               " << std::endl;
	file << "               ~  \\ //  ~                 " << std::endl;
	file << "           _- -   | | _- _                " << std::endl;
	file << "             _ -  | |   -_                " << std::endl;
	file << "                 /   \\                    " << std::endl;

	if (file.bad())
		throw ShrubberyCreationForm::WriteException();

	file.close();
	if (file.bad())
		throw ShrubberyCreationForm::CloseException();
}

const char	*ShrubberyCreationForm::OpenException::what() const throw()
{
	return "File could not be opened";
}

const char	*ShrubberyCreationForm::WriteException::what() const throw()
{
	return "File could not be written";
}

const char	*ShrubberyCreationForm::CloseException::what() const throw()
{
	return "File could not be closed";
}
