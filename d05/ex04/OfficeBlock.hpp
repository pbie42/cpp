/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:50:03 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 16:46:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_H
#define OFFICEBLOCK_H

#include <iostream>
#include <string>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

class OfficeBlock
{
	private:
		OfficeBlock(OfficeBlock const &f);
		OfficeBlock & operator=(OfficeBlock const &rhs);
		Intern *_intern;
		Bureaucrat *_signer;
		Bureaucrat *_executor;
		Form *_form;
	protected:
		/* data */
	public:
		OfficeBlock(/* args */);
		virtual ~OfficeBlock();
		void setIntern(Intern *);
		void setSigner(Bureaucrat *);
		void setExecutor(Bureaucrat *);
		void doBureaucracy(std::string const & type, std::string const & target);
		class InternException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				InternException(/* args */);
				InternException(InternException const &f);
				virtual ~InternException() throw();
				InternException & operator=(InternException const &rhs);
				virtual const char* what() const throw();
		};

		class SignerException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				SignerException(/* args */);
				SignerException(SignerException const &f);
				virtual ~SignerException() throw();
				SignerException & operator=(SignerException const &rhs);
				virtual const char* what() const throw();
		};

		class ExecutorException : public std::exception
		{
			private:
				/* data */
			protected:
				/* data */
			public:
				ExecutorException(/* args */);
				ExecutorException(ExecutorException const &f);
				virtual ~ExecutorException() throw();
				ExecutorException & operator=(ExecutorException const &rhs);
				virtual const char* what() const throw();
		};
};

OfficeBlock::OfficeBlock(/* args */) :
_intern(NULL),
_signer(NULL),
_executor(NULL),
_form(NULL)
{
}

OfficeBlock::OfficeBlock(const OfficeBlock &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

OfficeBlock::~OfficeBlock()
{
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void OfficeBlock::setIntern(Intern *i)
{
	this->_intern = i;
}

void OfficeBlock::setSigner(Bureaucrat *s)
{
	this->_signer = s;
}

void OfficeBlock::setExecutor(Bureaucrat *e)
{
	this->_executor = e;
}

void OfficeBlock::doBureaucracy(std::string const & type, std::string const & target)
{
	if (!this->_intern)
		throw OfficeBlock::InternException();
	if (!this->_signer)
		throw OfficeBlock::SignerException();
	if (!this->_executor)
		throw OfficeBlock::ExecutorException();
	this->_form = this->_intern->makeForm(type, target);
	this->_signer->signForm((*this->_form));
	this->_executor->executeForm((*this->_form));
}


// Intern Exception ------------------------------------------------------------

OfficeBlock::InternException::InternException(/* args */)
{
}

OfficeBlock::InternException::InternException(const InternException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

OfficeBlock::InternException::~InternException() throw()
{
}

OfficeBlock::InternException & OfficeBlock::InternException::operator=(InternException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* OfficeBlock::InternException::what() const throw()
{
	return ("The Intern does not exist!");
}

// Signer Exception ------------------------------------------------------------

OfficeBlock::SignerException::SignerException(/* args */)
{
}

OfficeBlock::SignerException::SignerException(const SignerException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

OfficeBlock::SignerException::~SignerException() throw()
{
}

OfficeBlock::SignerException & OfficeBlock::SignerException::operator=(SignerException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* OfficeBlock::SignerException::what() const throw()
{
	return ("The signer does not exist!");
}

// Executor Exception ----------------------------------------------------------

OfficeBlock::ExecutorException::ExecutorException(/* args */)
{
}

OfficeBlock::ExecutorException::ExecutorException(const ExecutorException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

OfficeBlock::ExecutorException::~ExecutorException() throw()
{
}

OfficeBlock::ExecutorException & OfficeBlock::ExecutorException::operator=(ExecutorException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* OfficeBlock::ExecutorException::what() const throw()
{
	return ("The executor does not exist!");
}

#endif // OFFICEBLOCK_H
