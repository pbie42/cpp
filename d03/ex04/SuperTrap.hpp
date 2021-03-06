/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:45:13 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 16:08:24 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_H
#define SUPERTRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>
#include <iostream>

class SuperTrap : public FragTrap, public NinjaTrap
{
private:
	using FragTrap::hitPoints;
	using FragTrap::maxHitPoints;
	using NinjaTrap::energyPoints;
	using NinjaTrap::maxEnergyPoints;
	using NinjaTrap::meleeAtkDmg;
	using FragTrap::rangedAtkDmg;
	using FragTrap::armorDmgReduction;
public:
	SuperTrap(/* args */);
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap &f);
	virtual ~SuperTrap();
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};




#endif // SUPERTRAP_H
