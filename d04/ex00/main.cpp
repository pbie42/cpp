/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:16:28 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:34:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Casualty.hpp"
#include "Fatality.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");
	Casualty dan("Dan");
	Fatality thomas("Thomas");

	Fatality testThomas(thomas);

	std::cout << robert << jim << joe << dan << thomas << testThomas;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(dan);
	robert.polymorph(thomas);
	robert.polymorph(testThomas);
	return 0;
}

