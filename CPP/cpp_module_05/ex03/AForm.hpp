#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				_signed;
		int const			gradeToSign;
		int const			gradeToExecute;

	public:
		Form();
		Form(std::string const name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		Form &operator=(Form const &rhs);
		virtual ~Form();

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void	beSigned(Bureaucrat const &bureaucrat);
		void	execute(Bureaucrat const &executor) const;

		virtual void	action() const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class AlreadySignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class UnsignedException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, Form const &form);

#endif
