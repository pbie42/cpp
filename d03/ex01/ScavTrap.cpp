/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:23:57 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 10:28:43 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(/* args */) :
hitPoints(100), maxHitPoints(100), energyPoints(50), maxEnergyPoints(50),
level(1), meleeAtkDmg(20), rangedAtkDmg(15), armorDmgReduction(3)
{
	this->name = "Standard";
	std::cout << "SCAV-TP unit named " << this->getName() << " built." << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
hitPoints(100), maxHitPoints(100), energyPoints(50), maxEnergyPoints(50),
level(1), meleeAtkDmg(20), rangedAtkDmg(15), armorDmgReduction(3)
{
	this->name = name;
	std::cout << "SCAV-TP unit named " << this->getName() << " built." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAV-TP named " << this->getName() << " has died." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;

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
	return *this;
}

void ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SCAV-TP <" << this->getName() << "> attacks " << "<" << target
	<< "> at range, causing " << this->getRangedAtkDmg() << " points of damage." << std::endl;
}
void ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SCAV-TP <" << this->getName() << "> attacks " << "<" << target
	<< "> with a melee attack, causing " << this->getMeleeAtkDmg() << " points of damage." << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
{
	int current_hp = this->getHitPoints();
	
	if ((current_hp + this->getArmorDmgReduction()) >= amount)
		this->setHitPoints(this->getHitPoints() - amount + this->getArmorDmgReduction());
	else this->setHitPoints(0);

	std::cout << "SCAV-TP <" << this->getName() << "> is attacked for " << amount
	<< " points of damage. Shield took " << this->getArmorDmgReduction() << " points of damage."
	<< " Current HP: " << this->getHitPoints() << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount)
{
	int current_hp = this->getHitPoints();

	if ((current_hp + amount) > this->getMaxHitPoints()) this->setHitPoints(100);
	else this->setHitPoints(this->getHitPoints() + amount);

	std::cout << "SCAV-TP <" << this->getName() << "> is repaired with "
	<< amount << " hit points. Current HP: " << this->getHitPoints() << std::endl;
}

void ScavTrap::challengeNewcomer() const
{
	std::string randomChallenge[5] = {
		"Count to 1000!", "Do a Barrel Roll!", "Call your mom and tell her you love her!",
		"Not drink for 3 months!", "Stop being French!"
	};
	srand(time(0) + rand());
	int random = rand() % 5;

	std::cout << "SCAV-TP <" << this->getName() << "> challenges you to "
	<< randomChallenge[random] << std::endl;
}

std::string ScavTrap::getName() const
{
	return this->name;
}

void ScavTrap::setName(std::string name)
{
	this->name = name;
}

unsigned int ScavTrap::getHitPoints() const
{
		return this->hitPoints;
}
void ScavTrap::setHitPoints(unsigned int hitPoints)
{
		this->hitPoints = hitPoints;
}
unsigned int ScavTrap::getMaxHitPoints() const
{
		return this->maxHitPoints;
}
void ScavTrap::setMaxHitPoints(unsigned int maxHitPoints)
{
		this->maxHitPoints = maxHitPoints;
}
unsigned int ScavTrap::getEnergyPoints() const
{
		return this->energyPoints;
}
void ScavTrap::setEnergyPoints(unsigned int energyPoints)
{
		this->energyPoints = energyPoints;
}
unsigned int ScavTrap::getMaxEnergyPoints() const
{
		return this->maxEnergyPoints;
}
void ScavTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints)
{
		this->maxEnergyPoints = maxEnergyPoints;
}
unsigned int ScavTrap::getLevel() const
{
		return this->level;
}
void ScavTrap::setLevel(unsigned int level)
{
		this->level = level;
}
unsigned int ScavTrap::getMeleeAtkDmg() const
{
		return this->meleeAtkDmg;
}
void ScavTrap::setMeleeAtkDmg(unsigned int meleeAtkDmg)
{
		this->meleeAtkDmg = meleeAtkDmg;
}
unsigned int ScavTrap::getRangedAtkDmg() const
{
		return this->rangedAtkDmg;
}
void ScavTrap::setRangedAtkDmg(unsigned int rangedAtkDmg)
{
		this->rangedAtkDmg = rangedAtkDmg;
}
unsigned int ScavTrap::getArmorDmgReduction() const
{
		return this->armorDmgReduction;
}
void ScavTrap::setArmorDmgReduction(unsigned int armorDmgReduction)
{
		this->armorDmgReduction = armorDmgReduction;
}
