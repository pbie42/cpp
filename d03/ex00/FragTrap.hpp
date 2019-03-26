/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:42:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 16:18:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>

class FragTrap
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
	FragTrap(/* args */);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	~FragTrap();
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);
	FragTrap & operator=(FragTrap const &rhs);
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


#endif // FRAGTRAP_H
