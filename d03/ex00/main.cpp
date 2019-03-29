/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:56:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 14:18:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap quincy = FragTrap("Quincy");
	FragTrap standard = FragTrap();
	FragTrap steve = FragTrap("Steve");

	FragTrap test = FragTrap(FragTrap("test"));
	test.meleeAttack("Rick");

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
	return 0;
}

