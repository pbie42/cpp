/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:33:25 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 21:04:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(/* args */)
{
}

Character::Character(std::string const & name) :
name(name),
ap(40),
weapon(NULL)
{
}

Character::Character(const Character &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Character::~Character()
{
}

void Character::recoverAP()
{
	int currentAP = this->getAP();
	if (currentAP + 10 > 40) this->setAP(40);
	else this->setAP(currentAP + 10);
	std::cout << this->getName() << " has recovered AP!" << std::endl;
}

void Character::removeAP(int amount)
{
	int currentAP = this->getAP();
	if (currentAP - amount < 0) this->setAP(0);
	else this->setAP(currentAP - amount);
}

Character & Character::operator=(Character const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setAP(rhs.getAP());
	this->weapon = rhs.getWeapon();
	this->name = rhs.getName();
	return *this;
}

void Character::attack(Enemy *e)
{
	const int weaponCost = this->weapon->getAPCost();

	if (e && this->weapon != NULL && this->getAP() - weaponCost > 0)
	{
		std::cout << this->getName() << " attacks "
		<< e->getType() << " with a "
		<< this->weapon->getName()
		<< std::endl;
		this->weapon->attack();
		e->takeDamage(this->weapon->getDamage());
		if (e && e->getHP() <= 0)
			delete e;
		this->removeAP(weaponCost);
	}
	else
	{
		std::cout << this->getName() << " does not have enough AP to attack!" << std::endl;
	}
	
}

void Character::equip(AWeapon *w)
{
	this->weapon = w;
}

std::string const &Character::getName() const
{
	return this->name;
}

int Character::getAP() const
{
	return this->ap;
}

AWeapon *Character::getWeapon() const
{
	return this->weapon;
}

void Character::setAP(int ap)
{
	this->ap = ap;
}

std::ostream & operator<<(std::ostream & o, Character const & rhs)
{
	std::stringstream ss;

	if (rhs.getWeapon() != NULL)
	{
		ss << rhs.getName() << " has " << rhs.getAP() << " AP and wields a "
		<< rhs.getWeapon()->getName();
		o << ss.str();
	}
	else
	{
		ss << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed";
		o << ss.str();
	}
	return o;
}
