/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:37:32 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 21:02:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* zaz = new Character("Zaz");

	Enemy *a = new SuperMutant();
	Enemy *b = new RadScorpion();

	std::cout << *zaz << std::endl;

	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz << std::endl;
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
	zaz->attack(a);
	std::cout << *zaz << std::endl;
	std::cout << *a << std::endl;
	zaz->equip(pr);
	std::cout << *zaz << std::endl;
	zaz->attack(a);
	std::cout << *a << std::endl;
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
	
	zaz->equip(pr);
	std::cout << *zaz << std::endl;
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
	zaz->attack(b);
	std::cout << *zaz << std::endl;
	std::cout << *b << std::endl;
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->equip(pr);
	std::cout << *zaz << std::endl;
	zaz->attack(b);
	std::cout << *b << std::endl;
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
		zaz->attack(b);
	std::cout << *b << std::endl;
		zaz->attack(b);
	std::cout << *b << std::endl;
	std::cout << *zaz << std::endl;
	return 0;
}
