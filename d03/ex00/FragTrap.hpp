/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:42:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/25 15:03:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>

class FragTrap
{
private:
	unsigned int hit_points;
	unsigned int max_hit_points;
	unsigned int energy_points;
	unsigned int max_energy_points;
	unsigned int level;
	unsigned int melee_atk_dmg;
	unsigned int ranged_atk_dmg;
	unsigned int armor_dmg_reduction;
	std::string name;
public:
	FragTrap(/* args */);
	FragTrap(std::string name);
	~FragTrap();
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);
	FragTrap & operator=(FragTrap const &rhs);
	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getMaxHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getMaxEnergyPoints(void) const;
	unsigned int getLevel(void) const;
	unsigned int getMeleeAttackDamage(void) const;
	unsigned int getRangedAttackDamage(void) const;
	unsigned int getArmorDamageReduction(void) const;
};


#endif // FRAGTRAP_H
