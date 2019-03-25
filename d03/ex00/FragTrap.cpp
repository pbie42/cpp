/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:49:05 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 16:12:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(/* args */) :
hit_points(100), max_hit_points(100), energy_points(100), max_energy_points(100),
level(1), melee_atk_dmg(30), ranged_atk_dmg(20), armor_dmg_reduction(5)
{
	this->name = "Standard";
	std::cout << "FR4G-TP unit named " << this->getName() << " built." << std::endl;
}

FragTrap::FragTrap(std::string name) :
hit_points(100), max_hit_points(100), energy_points(100), max_energy_points(100),
level(1), melee_atk_dmg(30), ranged_atk_dmg(20), armor_dmg_reduction(5)
{
	this->name = name;
	std::cout << "FR4G-TP unit named " << this->getName() << " built." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP name " << this->getName() << " has died." << std::endl;
}

void FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "FR4G-TP <" << this->getName() << "> attacks " << "<" << target
	<< "> at range, causing " << this->getRangedAttackDamage() << " points of damage." << std::endl;
}

void FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "FR4G-TP <" << this->getName() << "> attacks " << "<" << target
	<< "> with a melee attack, causing " << this->getMeleeAttackDamage() << " points of damage." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	int current_hp = this->getHitPoints();

	if ((current_hp + amount) > this->getMaxHitPoints()) this->hit_points = 100;
	else this->hit_points += amount;

	std::cout << "FR4G-TP <" << this->getName() << "> is repaired with "
	<< amount << " hit points. Current HP: " << this->getHitPoints() << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	int current_hp = this->getHitPoints();
	
	if ((current_hp + this->getArmorDamageReduction()) >= amount)
		this->hit_points -= (amount - this->getArmorDamageReduction());
	else this->hit_points = 0;

	std::cout << "FR4G-TP <" << this->getName() << "> is attacked for " << amount
	<< " points of damage. Current HP: " << this->getHitPoints() << std::endl;
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
		<< (random > 2 ? this->getRangedAttackDamage() : this->getMeleeAttackDamage())
		<< " points of damage."<< std::endl;
		this->energy_points -= 25;
	}
	else
		std::cout << "Sorry but you're out of energy points!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;

	std::cout << "<" << this->getName() << "> is now ";

	this->name = rhs.getName();
	this->hit_points = rhs.getHitPoints();
	this->max_hit_points = rhs.getMaxHitPoints();
	this->energy_points = rhs.getEnergyPoints();
	this->max_energy_points = rhs.getMaxEnergyPoints();
	this->level = rhs.getLevel();
	this->melee_atk_dmg = rhs.getMeleeAttackDamage();
	this->ranged_atk_dmg = rhs.getRangedAttackDamage();
	this->armor_dmg_reduction = rhs.getArmorDamageReduction();

	std::cout << "<" << this->name << ">" << std::endl;
	return *this;
}

std::string FragTrap::getName(void) const
{
	return this->name;
}

unsigned int FragTrap::getHitPoints(void) const
{
	return this->hit_points;
}

unsigned int FragTrap::getMaxHitPoints(void) const
{
	return this->max_hit_points;
}

unsigned int FragTrap::getEnergyPoints(void) const
{
	return this->energy_points;
}

unsigned int FragTrap::getMaxEnergyPoints(void) const
{
	return this->max_energy_points;
}

unsigned int FragTrap::getLevel(void) const
{
	return this->level;
}

unsigned int FragTrap::getMeleeAttackDamage(void) const
{
	return this->melee_atk_dmg;
}

unsigned int FragTrap::getRangedAttackDamage(void) const
{
	return this->ranged_atk_dmg;
}

unsigned int FragTrap::getArmorDamageReduction(void) const
{
	return this->armor_dmg_reduction;
}

