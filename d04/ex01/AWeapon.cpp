/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:32:17 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:40:41 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(/* args */)
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
name(name),
apcost(apcost),
damage(damage)
{
}

AWeapon::AWeapon(const AWeapon &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

AWeapon::~AWeapon()
{
}

AWeapon & AWeapon::operator=(AWeapon const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->name = rhs.getName();
	this->apcost = rhs.getAPCost();
	this->damage = rhs.getDamage();
	return *this;
}

std::string const &AWeapon::getName() const
{
	return this->name;
}
int AWeapon::getAPCost() const
{
	return this->apcost;
}
void AWeapon::setAPCost(int apcost)
{
	this->apcost = apcost;
}

int AWeapon::getDamage() const
{
	return this->damage;
}
void AWeapon::setDamage(int damage)
{
	this->damage = damage;
}
