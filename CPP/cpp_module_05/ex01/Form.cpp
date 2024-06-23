#include "Form.hpp"

Form::Form() :
	name("default"),
	_signed(false),
	gradeToSign(150),
	gradeToExecute(150)
{}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) :
	name(name),
	_signed(false),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &copy) :
	name(copy.name),
	_signed(copy._signed),
	gradeToSign(copy.gradeToSign),
	gradeToExecute(copy.gradeToExecute)
{
	*this = copy;
}

Form &Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	return *this;
}

Form::~Form() {}

std::string const	Form::getName() const
{
	return this->name;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

int	Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		throw Form::AlreadySignedException();
	else
		this->_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << " is "
	<< (form.getSigned() ? "signed" : "unsigned")
	<< ", it requires a grade of " << form.getGradeToSign()
	<< " to be signed and a grade of " << form.getGradeToExecute()
	<< " to be executed" << std::endl;
	return out;
}
