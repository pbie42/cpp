/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:56:59 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 22:40:23 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string target, std::string name, int gradeRequiredToSign, int gradeRequiredToExecute):
_name(name),
_target(target),
_signed(false),
_gradeRequiredToSign(gradeRequiredToSign),
_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeRequiredToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
	if (gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &f):
_name(f.getName()),
_target(f.getTarget()),
_signed(f.getSigned()),
_gradeRequiredToSign(f.getGradeRequiredToSign()),
_gradeRequiredToExecute(f.getGradeRequiredToExecute())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Form::~Form()
{
}

Form & Form::operator=(Form const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

int Form::getGradeRequiredToSign() const
{
	return this->_gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
	return this->_gradeRequiredToExecute;
}

bool Form::getSigned() const
{
	return this->_signed;
}

std::string const &Form::getName() const
{
	return this->_name;
}

std::string const &Form::getTarget() const
{
	return this->_target;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeRequiredToSign())
	{
		std::cout << b.getName() << " cannot sign " << this->getName() << " because ";
		throw Form::GradeTooHighException();
	}
	if (this->getSigned())
	{
		std::cout << b.getName() << " cannot sign form " << this->getName()
		<< " because it is already signed" << std::endl;
	}
	else
	{
		std::cout << b.getName() << " successfully signed form " << this->getName() << std::endl;
		this->_signed = true;
	}
}

void Form::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned() || this->getGradeRequiredToExecute() < executor.getGrade())
	{
		std::cout << executor.getName() << " cannot execute " << this->getName() << " because ";
		if (!this->getSigned())
			throw Form::NotSignedException();
		if (this->getGradeRequiredToExecute() < executor.getGrade())
			throw Form::GradeTooHighException();
	}
	std::cout << executor.getName() << " successfully executed form " << this->getName() << std::endl;
	this->action();
}

// Grade Too Low ---------------------------------------------------------------

Form::GradeTooLowException::GradeTooLowException(/* args */)
{
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

Form::GradeTooLowException & Form::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The Form grade is too low!");
}

// Grade Too High --------------------------------------------------------------


Form::GradeTooHighException::GradeTooHighException(/* args */)
{
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

Form::GradeTooHighException & Form::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The Form grade is too high!");
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	std::stringstream ss;

	const std::string isSigned = rhs.getSigned() ? "signed" : "not signed";;

	ss << "Form requires grade level " << rhs.getGradeRequiredToSign() << " to sign"
	<< " and requires grade level " << rhs.getGradeRequiredToExecute() << " to execute and is "
	<< isSigned;
	o << ss.str();
	return o;
}

// Not Signed ------------------------------------------------------------------

Form::NotSignedException::NotSignedException(/* args */)
{
}

Form::NotSignedException::NotSignedException(const NotSignedException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Form::NotSignedException::~NotSignedException() throw()
{
}

Form::NotSignedException & Form::NotSignedException::operator=(NotSignedException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Form::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}
