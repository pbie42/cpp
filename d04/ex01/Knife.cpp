/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knife.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:27:14 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:47:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Knife.hpp"

Knife::Knife(/* args */) :
AWeapon("Knife", 4, 20)
{
}

Knife::Knife(const Knife &f) :
AWeapon("Knife", 10, 60)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Knife::~Knife()
{
}

void Knife::attack() const
{
	std::cout << "* snikttt *" << std::endl;
}

Knife & Knife::operator=(Knife const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return *this;
}
