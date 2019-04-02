/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:43:01 by pbie              #+#    #+#             */
/*   Updated: 2019/04/02 14:12:57 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(/* args */)
{
}

Intern::Intern(const Intern &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

Form *Intern::createPardon(std::string const & target) const
{
	return new PresidentialPardonForm(target);
}
Form *Intern::createRobotomy(std::string const & target) const
{
	return new RobotomyRequestForm(target);
}
Form *Intern::createShrubbery(std::string const & target) const
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string const & type, std::string const & target) const
{
	typedef Form* (Intern::*Actions)(std::string const & target) const;

	Actions actions[3] = { &Intern::createPardon, &Intern::createRobotomy, &Intern::createShrubbery };

	std::string actionsNames[] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	int attackNum = 3;
	int x = 0;

	while(x < attackNum){
		if (actionsNames[x] == type)
			return (this->*actions[x])(target);
		x++;
	}
	throw Intern::MakeFormException();
	return NULL;
}


// Make Form Exception

Intern::MakeFormException::MakeFormException(/* args */)
{
}

Intern::MakeFormException::MakeFormException(const MakeFormException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Intern::MakeFormException::~MakeFormException() throw()
{
}

Intern::MakeFormException & Intern::MakeFormException::operator=(MakeFormException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* Intern::MakeFormException::what() const throw()
{
	return ("Not a valid Form!");
}
