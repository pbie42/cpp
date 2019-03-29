/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:53:57 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 18:56:17 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(/* args */) : AMateria("cure")
{
}

Cure::Cure(const Cure &f) : AMateria("cure")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Cure::~Cure()
{
}

Cure & Cure::operator=(Cure const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.getType();
		this->xp_ = rhs.getXP();
	}
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals" << target.getName() << "'s wounds *" << std::endl;
}
