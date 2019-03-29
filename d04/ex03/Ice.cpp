/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:57 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 21:59:59 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(/* args */) : AMateria("ice")
{
}

Ice::Ice(const Ice &f) : AMateria("ice")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Ice::~Ice()
{
}

Ice & Ice::operator=(Ice const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		this->xp_ = rhs.getXP();
	}
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
