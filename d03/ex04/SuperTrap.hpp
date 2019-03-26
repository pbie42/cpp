/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:45:13 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 16:27:13 by pbie             ###   ########.fr       */
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
	~SuperTrap();
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
};




#endif // SUPERTRAP_H
