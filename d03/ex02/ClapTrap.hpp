/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:40:52 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 16:22:00 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
	private:
		/* data */
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int maxHitPoints;
		unsigned int energyPoints;
		unsigned int maxEnergyPoints;
		unsigned int level;
		unsigned int meleeAtkDmg;
		unsigned int rangedAtkDmg;
		unsigned int armorDmgReduction;
	public:
		ClapTrap(
		std::string name,
		unsigned int hitPoints,
		unsigned int maxHitPoints,
		unsigned int energyPoints,
		unsigned int maxEnergyPoints,
		unsigned int level,
		unsigned int meleeAtkDmg,
		unsigned int rangedAtkDmg,
		unsigned int armorDmgReduction
		);
		ClapTrap();
		ClapTrap(const ClapTrap &f);
		~ClapTrap();
		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		ClapTrap & operator=(ClapTrap const &rhs);
		std::string getName() const;
		void setName(std::string name);
		unsigned int getHitPoints() const;
		void setHitPoints(unsigned int hitPoints);
		unsigned int getMaxHitPoints() const;
		void setMaxHitPoints(unsigned int maxHitPoints);
		unsigned int getEnergyPoints() const;
		void setEnergyPoints(unsigned int energyPoints);
		unsigned int getMaxEnergyPoints() const;
		void setMaxEnergyPoints(unsigned int maxEnergyPoints);
		unsigned int getLevel() const;
		void setLevel(unsigned int level);
		unsigned int getMeleeAtkDmg() const;
		void setMeleeAtkDmg(unsigned int meleeAtkDmg);
		unsigned int getRangedAtkDmg() const;
		void setRangedAtkDmg(unsigned int rangedAtkDmg);
		unsigned int getArmorDmgReduction() const;
		void setArmorDmgReduction(unsigned int armorDmgReduction);
};

#endif // CLAPTRAP_H
