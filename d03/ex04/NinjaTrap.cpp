/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:13:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 20:35:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(/* args */)
{
	this->name = "Standard Ninja";
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->meleeAtkDmg = 60;
	this->rangedAtkDmg = 5;
	this->armorDmgReduction = 0;
	std::cout << "NINJA-TP unit named <" << this->getName() << "> built." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 60;
	this->maxHitPoints = 60;
	this->energyPoints = 120;
	this->maxEnergyPoints = 120;
	this->level = 1;
	this->meleeAtkDmg = 60;
	this->rangedAtkDmg = 5;
	this->armorDmgReduction = 0;
	std::cout << "NINJA-TP unit named <" << this->getName() << "> built." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NINJA-TP unit named <" << this->getName() << "> destroyed." << std::endl;
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
	std::cout << "NINJA-TP ranged attack and ";
	ClapTrap::rangedAttack(target);
}
void NinjaTrap::meleeAttack(std::string const & target) const
{
	std::cout << "NINJA-TP melee attack and ";
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
