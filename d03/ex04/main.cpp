/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:56:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 14:31:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

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

	std::cout << "\n" << std::endl;
	
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

	std::cout << "\n" << std::endl;

	NinjaTrap tenchu = NinjaTrap("Tenchu");
	NinjaTrap shinobi = NinjaTrap("Shinobi");
	ClapTrap noName = ClapTrap();

	tenchu.takeDamage(25);
	tenchu.takeDamage(25);
	tenchu.takeDamage(25);
	tenchu.takeDamage(25);
	tenchu.takeDamage(25);
	tenchu.takeDamage(25);

	tenchu.beRepaired(25);
	tenchu.beRepaired(25);

	tenchu.takeDamage(75);

	tenchu.beRepaired(200);

	tenchu.meleeAttack("Daniel");
	tenchu.rangedAttack("Daniel");

	tenchu.ninjaShoebox(noName);
	tenchu.ninjaShoebox(josephine);
	tenchu.ninjaShoebox(quincy);
	tenchu.ninjaShoebox(shinobi);

	std::cout << "\n" << std::endl;


	SuperTrap super = SuperTrap("Superman");

	super.meleeAttack("Daniel Hadley");
	super.rangedAttack("Daniel Hadley");

	std::cout << "\n" << std::endl;
	
	return 0;
}

