/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:23:26 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 16:46:06 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>

class ScavTrap
{
private:
	unsigned int hitPoints;
	unsigned int maxHitPoints;
	unsigned int energyPoints;
	unsigned int maxEnergyPoints;
	unsigned int level;
	unsigned int meleeAtkDmg;
	unsigned int rangedAtkDmg;
	unsigned int armorDmgReduction;
	std::string name;
public:
	ScavTrap(/* args */);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap & ScavTrap::operator=(ScavTrap const &rhs);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
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


#endif // SCAVTRAP_H
