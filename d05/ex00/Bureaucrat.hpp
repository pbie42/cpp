/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:43:20 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 14:12:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <sstream>

class Bureaucrat
{
	private:
		/* data */
	protected:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(/* args */);
		Bureaucrat(Bureaucrat const &f);
		virtual ~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const &rhs);
		std::string const &getName() const;
		int getGrade() const;
		void incGrade();
		void decGrade();
		class GradeTooHighException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				GradeTooHighException(/* args */);
				GradeTooHighException(GradeTooHighException const &f);
				virtual ~GradeTooHighException();
				GradeTooHighException & operator=(GradeTooHighException const &rhs);
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				GradeTooLowException(/* args */);
				GradeTooLowException(GradeTooLowException const &f);
				virtual ~GradeTooLowException();
				GradeTooLowException & operator=(GradeTooLowException const &rhs);
				virtual const char* what() const throw();
		};
};

Bureaucrat::Bureaucrat(/* args */)
{
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
	try
	{
		if (this->getGrade() - 1 < 1)
		{
			Bureaucrat::GradeTooHighException exception;
			throw exception.what();
		}
		else
			this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	std::stringstream ss;

	ss << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	o << ss.str();
	return o;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);


// Grade Too High

Bureaucrat::GradeTooHighException::GradeTooHighException(/* args */)
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
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

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The given bureaucrat grade is too low!");
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

Bureaucrat::GradeTooLowException::~GradeTooLowException()
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
	return ("The given bureaucrat grade is too high!");
}

#endif // BUREAUCRAT_H
