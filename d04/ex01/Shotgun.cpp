/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shotgun.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:27:14 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:45:15 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shotgun.hpp"

Shotgun::Shotgun(/* args */) :
AWeapon("Shotgun", 10, 60)
{
}

Shotgun::Shotgun(const Shotgun &f) :
AWeapon("Shotgun", 10, 60)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Shotgun::~Shotgun()
{
}

void Shotgun::attack() const
{
	std::cout << "* kaBLOW *" << std::endl;
}

Shotgun & Shotgun::operator=(Shotgun const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setAPCost(rhs.getAPCost());
	this->setDamage(rhs.getDamage());
	return *this;
}
