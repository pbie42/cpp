/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:56:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 10:29:51 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	FragTrap quincy = FragTrap("Quincy");
	FragTrap standard = FragTrap();
	FragTrap steve = FragTrap("Steve");

	quincy.vaulthunter_dot_exe("Dan");
	quincy.vaulthunter_dot_exe("Dan");
	quincy.vaulthunter_dot_exe("Dan");
	quincy.vaulthunter_dot_exe("Dan");
	quincy.vaulthunter_dot_exe("Dan");

	quincy.takeDamage(25);
	quincy.takeDamage(25);
	quincy.takeDamage(25);
	quincy.takeDamage(25);
	quincy.takeDamage(25);
	quincy.takeDamage(25);

	quincy.beRepaired(25);
	quincy.beRepaired(25);

	quincy.takeDamage(75);

	quincy.beRepaired(200);

	quincy.meleeAttack("Dan");
	quincy.rangedAttack("Dan");

	standard = steve;

	standard.meleeAttack("Dan");
	
	ScavTrap josephine = ScavTrap("Josephine");
	ScavTrap basic = ScavTrap();
	ScavTrap lucien = ScavTrap("Lucien");

	josephine.challengeNewcomer();
	josephine.challengeNewcomer();
	josephine.challengeNewcomer();
	josephine.challengeNewcomer();
	josephine.challengeNewcomer();

	josephine.takeDamage(25);
	josephine.takeDamage(25);
	josephine.takeDamage(25);
	josephine.takeDamage(25);
	josephine.takeDamage(25);
	josephine.takeDamage(25);

	josephine.beRepaired(25);
	josephine.beRepaired(25);

	josephine.takeDamage(75);

	josephine.beRepaired(200);

	josephine.meleeAttack("Daniel");
	josephine.rangedAttack("Daniel");

	basic = lucien;

	basic.meleeAttack("Daniel");
	return 0;
}

