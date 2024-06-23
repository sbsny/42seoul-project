#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm();

		void	action() const;

		class OpenException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class WriteException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class CloseException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
