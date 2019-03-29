/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:41:28 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 15:53:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 0;
	this->maxHitPoints = 0;
	this->energyPoints = 0;
	this->maxEnergyPoints = 0;
	this->level = 1;
	this->meleeAtkDmg = 0;
	this->rangedAtkDmg = 0;
	this->armorDmgReduction = 0;
	std::cout << "A new ClapTrap named <" << this->getName() << "> has been created!" << std::endl;
}

ClapTrap::ClapTrap()
{
	this->name = "Standard ClapTrap";
	this->hitPoints = 0;
	this->maxHitPoints = 0;
	this->energyPoints = 0;
	this->maxEnergyPoints = 0;
	this->level = 1;
	this->meleeAtkDmg = 0;
	this->rangedAtkDmg = 0;
	this->armorDmgReduction = 0;
	std::cout << "A ClapTrap named <" << this->getName() << "> has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

ClapTrap::~ClapTrap()
{
	std::cout << "A ClapTrap named <" << this->getName() << "> has been destroyed!" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;

	if (this != &rhs)
	{
		std::cout << "<" << this->getName() << "> is now ";

		this->name = rhs.getName();
		this->hitPoints = rhs.getHitPoints();
		this->maxHitPoints = rhs.getMaxHitPoints();
		this->energyPoints = rhs.getEnergyPoints();
		this->maxEnergyPoints = rhs.getMaxEnergyPoints();
		this->level = rhs.getLevel();
		this->meleeAtkDmg = rhs.getMeleeAtkDmg();
		this->rangedAtkDmg = rhs.getRangedAtkDmg();
		this->armorDmgReduction = rhs.getArmorDmgReduction();

		std::cout << "<" << this->name << ">" << std::endl;
	}
	return *this;
}

void ClapTrap::rangedAttack(std::string const & target) const
{
	std::cout << "<" << this->getName() << "> attacks " << "<" << target
	<< "> at range, causing " << this->getRangedAtkDmg() << " points of damage." << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target) const
{
	std::cout << "<" << this->getName() << "> attacks " << "<" << target
	<< "> with a melee attack, causing " << this->getMeleeAtkDmg() << " points of damage." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int current_hp = this->getHitPoints();
	
	if ((current_hp + this->getArmorDmgReduction()) >= amount)
		this->setHitPoints(this->getHitPoints() - amount + this->getArmorDmgReduction());
	else this->setHitPoints(0);

	std::cout << "<" << this->getName() << "> is attacked for " << amount
	<< " points of damage. Shield took " << this->getArmorDmgReduction() << " points of damage."
	<< " Current HP: " << this->getHitPoints() << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	int current_hp = this->getHitPoints();

	if ((current_hp + amount) > this->getMaxHitPoints()) this->setHitPoints(100);
	else this->setHitPoints(this->getHitPoints() + amount);

	std::cout << "<" << this->getName() << "> is repaired with "
	<< amount << " hit points. Current HP: " << this->getHitPoints() << std::endl;
}

std::string const &ClapTrap::getName() const
{
	return this->name;
}

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

unsigned int ClapTrap::getHitPoints() const
{
		return this->hitPoints;
}
void ClapTrap::setHitPoints(unsigned int hitPoints)
{
		this->hitPoints = hitPoints;
}
unsigned int ClapTrap::getMaxHitPoints() const
{
		return this->maxHitPoints;
}
void ClapTrap::setMaxHitPoints(unsigned int maxHitPoints)
{
		this->maxHitPoints = maxHitPoints;
}
unsigned int ClapTrap::getEnergyPoints() const
{
		return this->energyPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
		this->energyPoints = energyPoints;
}
unsigned int ClapTrap::getMaxEnergyPoints() const
{
		return this->maxEnergyPoints;
}
void ClapTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints)
{
		this->maxEnergyPoints = maxEnergyPoints;
}
unsigned int ClapTrap::getLevel() const
{
		return this->level;
}
void ClapTrap::setLevel(unsigned int level)
{
		this->level = level;
}
unsigned int ClapTrap::getMeleeAtkDmg() const
{
		return this->meleeAtkDmg;
}
void ClapTrap::setMeleeAtkDmg(unsigned int meleeAtkDmg)
{
		this->meleeAtkDmg = meleeAtkDmg;
}
unsigned int ClapTrap::getRangedAtkDmg() const
{
		return this->rangedAtkDmg;
}
void ClapTrap::setRangedAtkDmg(unsigned int rangedAtkDmg)
{
		this->rangedAtkDmg = rangedAtkDmg;
}
unsigned int ClapTrap::getArmorDmgReduction() const
{
		return this->armorDmgReduction;
}
void ClapTrap::setArmorDmgReduction(unsigned int armorDmgReduction)
{
		this->armorDmgReduction = armorDmgReduction;
}

