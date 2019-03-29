/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:49:05 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 14:57:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(/* args */) : ClapTrap("Standard FR4G", 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "FR4G-TP unit named " << this->getName() << " built." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5)
{
	std::cout << "FR4G-TP unit named " << this->getName() << " built." << std::endl;
}

FragTrap::FragTrap(const FragTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP named " << this->getName() << " has died." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
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

void FragTrap::rangedAttack(std::string const & target) const
{
	std::cout << "FR4G-TP named ";
	ClapTrap::rangedAttack(target);
}
void FragTrap::meleeAttack(std::string const & target) const
{
	std::cout << "FR4G-TP named ";
	ClapTrap::meleeAttack(target);
}
void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FR4G-TP named ";
	ClapTrap::takeDamage(amount);
}
void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FR4G-TP named ";
	ClapTrap::beRepaired(amount);
}
