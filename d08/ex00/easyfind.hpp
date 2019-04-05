/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:36:34 by pbie              #+#    #+#             */
/*   Updated: 2019/04/05 15:06:29 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>

class NonExistantException : public std::exception
{
	private:
		/* data */
	protected:
		/* data */
	public:
		NonExistantException(/* args */);
		NonExistantException(NonExistantException const &f);
		virtual ~NonExistantException() throw();
		NonExistantException & operator=(NonExistantException const &rhs);
		virtual const char* what() const throw();
};

NonExistantException::NonExistantException(/* args */)
{
}

NonExistantException::NonExistantException(const NonExistantException &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

NonExistantException::~NonExistantException() throw()
{
}

NonExistantException & NonExistantException::operator=(NonExistantException const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

const char* NonExistantException::what() const throw()
{
	return ("The element does not exist!");
}

template< typename T >
int easyfind(T & container, int toFind)
{
	typename T::iterator itr;
	for(itr = container.begin(); itr != container.end(); itr++)
	{
		if (*itr == toFind)
			return *itr;
	}
	throw NonExistantException();
	return -1;
}

#endif // EASYFIND_H
