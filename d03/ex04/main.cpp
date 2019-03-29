/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:56:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 16:00:48 by pbie             ###   ########.fr       */
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
	std::cout << "before supertrap" << std::endl;
	std::cout << "\n" << std::endl;


	SuperTrap super = SuperTrap("Superman");

	std::cout << "\n" << std::endl;
	std::cout << "after supertrap" << std::endl;
	std::cout << "\n" << std::endl;

	super.meleeAttack("Daniel Hadley");
	super.rangedAttack("Daniel Hadley");
	super.ninjaShoebox(shinobi);
	super.vaulthunter_dot_exe("Daniel Hadley");
	super.takeDamage(25);
	super.takeDamage(25);
	super.takeDamage(25);
	super.takeDamage(25);
	super.takeDamage(25);
	super.takeDamage(25);

	super.beRepaired(25);
	super.beRepaired(25);

	super.takeDamage(75);

	super.beRepaired(200);

	std::cout << "\n" << std::endl;
	
	return 0;
}

