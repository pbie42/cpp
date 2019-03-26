/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:49:05 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 13:26:25 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(/* args */) :
hitPoints(100), maxHitPoints(100), energyPoints(100), maxEnergyPoints(100),
level(1), meleeAtkDmg(30), rangedAtkDmg(20), armorDmgReduction(5)
{
	this->name = "Standard FR4G";
	std::cout << "FR4G-TP unit named " << this->getName() << " built." << std::endl;
}

FragTrap::FragTrap(std::string name) :
hitPoints(100), maxHitPoints(100), energyPoints(100), maxEnergyPoints(100),
level(1), meleeAtkDmg(30), rangedAtkDmg(20), armorDmgReduction(5)
{
	this->name = name;
	std::cout << "FR4G-TP unit named " << this->getName() << " built." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP named " << this->getName() << " has died." << std::endl;
}

void FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "FR4G-TP <" << this->getName() << "> attacks " << "<" << target
	<< "> at range, causing " << this->getRangedAtkDmg() << " points of damage." << std::endl;
}

void FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "FR4G-TP <" << this->getName() << "> attacks " << "<" << target
	<< "> with a melee attack, causing " << this->getMeleeAtkDmg() << " points of damage." << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int current_hp = this->getHitPoints();
	
	if ((current_hp + this->getArmorDmgReduction()) >= amount)
		this->setHitPoints(this->getHitPoints() - amount + this->getArmorDmgReduction());
	else this->setHitPoints(0);

	std::cout << "FR4G-TP <" << this->getName() << "> is attacked for " << amount
	<< " points of damage. Shield took " << this->getArmorDmgReduction() << " points of damage."
	<< " Current HP: " << this->getHitPoints() << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	int current_hp = this->getHitPoints();

	if ((current_hp + amount) > this->getMaxHitPoints()) this->setHitPoints(100);
	else this->setHitPoints(this->getHitPoints() + amount);

	std::cout << "FR4G-TP <" << this->getName() << "> is repaired with "
	<< amount << " hit points. Current HP: " << this->getHitPoints() << std::endl;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string randomAttacks[5] = {
		"Back Hand", "What did the 5 fingers say to the side of the face? SLAP!",
		"Full Force Fisting", "The Bowl Disruptor", "Loogie"
	};
	srand(time(0) + rand());
	int random = rand() % 5;

	if (this->getEnergyPoints() >= 25)
	{
		std::cout << "FR4G-TP <" << this->getName() << "> used " << randomAttacks[random]
		<< " against " << target << " for "
		<< (random > 2 ? this->getRangedAtkDmg() : this->getMeleeAtkDmg())
		<< " points of damage."<< std::endl;
		this->energyPoints -= 25;
	}
	else
		std::cout << "Sorry but <" << this->getName() << "> is out of energy points!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
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

std::string FragTrap::getName() const
{
	return this->name;
}

void FragTrap::setName(std::string name)
{
	this->name = name;
}

unsigned int FragTrap::getHitPoints() const
{
		return this->hitPoints;
}
void FragTrap::setHitPoints(unsigned int hitPoints)
{
		this->hitPoints = hitPoints;
}
unsigned int FragTrap::getMaxHitPoints() const
{
		return this->maxHitPoints;
}
void FragTrap::setMaxHitPoints(unsigned int maxHitPoints)
{
		this->maxHitPoints = maxHitPoints;
}
unsigned int FragTrap::getEnergyPoints() const
{
		return this->energyPoints;
}
void FragTrap::setEnergyPoints(unsigned int energyPoints)
{
		this->energyPoints = energyPoints;
}
unsigned int FragTrap::getMaxEnergyPoints() const
{
		return this->maxEnergyPoints;
}
void FragTrap::setMaxEnergyPoints(unsigned int maxEnergyPoints)
{
		this->maxEnergyPoints = maxEnergyPoints;
}
unsigned int FragTrap::getLevel() const
{
		return this->level;
}
void FragTrap::setLevel(unsigned int level)
{
		this->level = level;
}
unsigned int FragTrap::getMeleeAtkDmg() const
{
		return this->meleeAtkDmg;
}
void FragTrap::setMeleeAtkDmg(unsigned int meleeAtkDmg)
{
		this->meleeAtkDmg = meleeAtkDmg;
}
unsigned int FragTrap::getRangedAtkDmg() const
{
		return this->rangedAtkDmg;
}
void FragTrap::setRangedAtkDmg(unsigned int rangedAtkDmg)
{
		this->rangedAtkDmg = rangedAtkDmg;
}
unsigned int FragTrap::getArmorDmgReduction() const
{
		return this->armorDmgReduction;
}
void FragTrap::setArmorDmgReduction(unsigned int armorDmgReduction)
{
		this->armorDmgReduction = armorDmgReduction;
}

