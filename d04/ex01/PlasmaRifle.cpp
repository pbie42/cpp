/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:27:14 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 23:27:33 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(/* args */) :
AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &f) :
AWeapon("Plasma Rifle", 5, 21)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return *this;
}
