/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:45:28 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 21:35:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);

	for(int i = 0; i < vlc->getCount(); i++)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;

	ISpaceMarine* rob = new TacticalMarine;
	ISpaceMarine* tim = new AssaultTerminator;
	Squad dopeSquad = Squad();
	dopeSquad.push(rob);
	dopeSquad.push(tim);

	std::cout << "about to enter dopesquad loop" << std::endl;
	for(int i = 0; i < dopeSquad.getCount(); i++)
	{
		ISpaceMarine* cur = dopeSquad.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	Squad test(dopeSquad);
	std::cout << "about to enter test loop" << std::endl;
	for(int i = 0; i < test.getCount(); i++)
	{
		ISpaceMarine* cur = test.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	return 0;
}

