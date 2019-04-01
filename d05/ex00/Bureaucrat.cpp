/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:03:16 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 20:05:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) :
_name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	std::cout << "Bureaucrat " << this->getName()
	<< " created with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incGrade()
{
	if (this->getGrade() - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decGrade()
{
	if (this->getGrade() + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	std::stringstream ss;

	ss << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	o << ss.str();
	return o;
}

// Grade Too High

Bureaucrat::GradeTooHighException::GradeTooHighException(/* args */)
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The bureaucrat grade is too high!");
}

// Grade Too Low

Bureaucrat::GradeTooLowException::GradeTooLowException(/* args */)
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat grade is too low!");
}
