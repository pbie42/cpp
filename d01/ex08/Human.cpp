/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:10:42 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 14:44:42 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <string>
#include <iostream>

void Human::meleeAttack(std::string const &target)
{
	std::cout << "Melee attack against " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "Ranged attack against " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "Intimidating shout against " << target << std::endl;
}

void Human::action(std::string const &action_name, std::string const &target)
{
	typedef void (Human::*Actions)(std::string const & target);

	Actions actions[3] = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };

	std::string actionsNames[] =
	{
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};

	int attackNum = 3;
	int x = 0;

	while(x < attackNum){
		if (actionsNames[x] == action_name)
			(this->*actions[x])(target);
		x++;
	}
}


