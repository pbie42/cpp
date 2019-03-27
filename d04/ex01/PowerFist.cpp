/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:27:44 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 23:28:52 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(/* args */) :
AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PowerFist &f) :
AWeapon("Power Fist", 8, 50)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist & PowerFist::operator=(PowerFist const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return *this;
}
