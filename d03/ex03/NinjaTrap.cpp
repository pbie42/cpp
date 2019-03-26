/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:13:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 13:24:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(/* args */) : ClapTrap("Standard Ninja", 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "NINJA-TP unit named " << this->getName() << " built." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0)
{
	std::cout << "NINJA-TP unit named " << this->getName() << " built." << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJA-TP unit named " << this->getName() << " built." << std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const &rhs)
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

void NinjaTrap::ninjaShoebox(FragTrap & target) const
{
	std::cout << "NINJA-TP <" << this->getName() << "> attacks FR4G-TP <"
	<< target.getName() << "> with it's Frag Out attack!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap & target) const
{
	std::cout << "NINJA-TP <" << this->getName() << "> attacks SCAV-TP <"
	<< target.getName() << "> with it's Scavenger attack!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap & target) const
{
	std::cout << "NINJA-TP <" << this->getName() << "> attacks CLAP-TP <"
	<< target.getName() << "> with it's Clap Back attack!" << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap & target) const
{
	std::cout << "NINJA-TP <" << this->getName() << "> attacks NINJA-TP <"
	<< target.getName() << "> with it's Ninja Star attack!" << std::endl;
}

void NinjaTrap::rangedAttack(std::string const & target) const
{
	std::cout << "NINJA-TP named ";
	ClapTrap::rangedAttack(target);
}
void NinjaTrap::meleeAttack(std::string const & target) const
{
	std::cout << "NINJA-TP named ";
	ClapTrap::meleeAttack(target);
}
void NinjaTrap::takeDamage(unsigned int amount)
{
	std::cout << "NINJA-TP named ";
	ClapTrap::takeDamage(amount);
}
void NinjaTrap::beRepaired(unsigned int amount)
{
	std::cout << "NINJA-TP named ";
	ClapTrap::beRepaired(amount);
}
