/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:23:57 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 15:55:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(/* args */)
{
	this->name = "Standard SCAV";
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAtkDmg = 20;
	this->rangedAtkDmg = 25;
	this->armorDmgReduction = 3;
	std::cout << "SCAV-TP unit named <" << this->getName() << "> built." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->maxHitPoints = 100;
	this->energyPoints = 50;
	this->maxEnergyPoints = 50;
	this->level = 1;
	this->meleeAtkDmg = 20;
	this->rangedAtkDmg = 25;
	this->armorDmgReduction = 3;
	std::cout << "SCAV-TP unit named <" << this->getName() << "> built." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAV-TP named <" << this->getName() << "> has died." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &rhs)
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

void ScavTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SCAV-TP named ";
	ClapTrap::rangedAttack(target);
}
void ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SCAV-TP named ";
	ClapTrap::meleeAttack(target);
}
void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "SCAV-TP named ";
	ClapTrap::takeDamage(amount);
}
void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "SCAV-TP named ";
	ClapTrap::beRepaired(amount);
}
