/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:45:29 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 21:31:25 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(/* args */) :
ClapTrap("Standard SuperTrap"),
FragTrap("Standard SuperTrap"),
NinjaTrap("Standard SuperTrap")
{
	NinjaTrap ninja;
	FragTrap frag;

	this->name = "Standard SUPER-TP";
	this->hitPoints = frag.getHitPoints();
	this->maxHitPoints = frag.getMaxHitPoints();
	this->energyPoints = ninja.getEnergyPoints();
	this->maxEnergyPoints = ninja.getMaxEnergyPoints();
	this->level = 1;
	this->meleeAtkDmg = ninja.getMeleeAtkDmg();
	this->rangedAtkDmg = frag.getRangedAtkDmg();
	this->armorDmgReduction = frag.getArmorDmgReduction();
	std::cout << "SUPER-TP named <" << this->getName() << "> created!" << std::endl;
}

SuperTrap::SuperTrap(std::string name) :
ClapTrap(name),
FragTrap(name),
NinjaTrap(name)
{
	NinjaTrap ninja;
	FragTrap frag;

	this->name = name;
	this->hitPoints = frag.getHitPoints();
	this->maxHitPoints = frag.getMaxHitPoints();
	this->energyPoints = ninja.getEnergyPoints();
	this->maxEnergyPoints = ninja.getMaxEnergyPoints();
	this->level = 1;
	this->meleeAtkDmg = ninja.getMeleeAtkDmg();
	this->rangedAtkDmg = frag.getRangedAtkDmg();
	this->armorDmgReduction = frag.getArmorDmgReduction();
	std::cout << "SUPER-TP named <" << this->getName() << "> created!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUPER-TP named <" << this->getName() << "> destroyed!" << std::endl;
}

void SuperTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SUPER-TP named " << "<" << this->getName() << "> uses ";
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SUPER-TP named " << "<" << this->getName() << "> uses ";
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::takeDamage(unsigned int amount)
{
	std::cout << "SUPER-TP named ";
	ClapTrap::takeDamage(amount);
}

void SuperTrap::beRepaired(unsigned int amount)
{
	std::cout << "SUPER-TP named ";
	ClapTrap::beRepaired(amount);
}
