/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:02:00 by pbie              #+#    #+#             */
/*   Updated: 2019/03/18 14:41:37 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human bill = Human();

	bill.action("meleeAttack", "Steve");
	bill.action("rangedAttack", "Steve");
	bill.action("intimidatingShout", "Steve");
	return 0;
}
