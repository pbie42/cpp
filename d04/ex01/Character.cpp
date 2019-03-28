/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:33:25 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 17:42:43 by pbie             ###   ########.fr       */
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
	if (this->weapon != NULL)
	{
		std::cout << this->getName() << " attacks "
		<< e->getType() << " with a "
		<< this->weapon->getName()
		<< std::endl;
		e->takeDamage(this->weapon->getDamage());
		if (e->getHP() <= 0) delete e;
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
		std::cout << "has a weapon" << std::endl;
		ss << rhs.getName() << " has " << rhs.getAP() << " AP and wields a"
		<< rhs.getWeapon()->getName();
		o << ss.str();
	}
	else
	{
		std::cout << "has no weapon" << std::endl;
		ss << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed";
		o << ss.str();
	}
	return o;
}
