/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:37:32 by pbie              #+#    #+#             */
/*   Updated: 2019/04/01 22:03:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Shotgun.hpp"
#include "Knife.hpp"
#include "Dan.hpp"
#include "Bear.hpp"

int main()
{
	Character* zaz = new Character("Zaz");

	Enemy *a = new SuperMutant();
	Enemy *b = new RadScorpion();
	Enemy *dan = new Dan();
	Enemy *bear = new Bear();

	std::cout << *zaz << std::endl;

	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();
	AWeapon *sg = new Shotgun();
	AWeapon *k = new Knife();

	zaz->equip(pr);
	std::cout << *zaz << std::endl;
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
	zaz->attack(a);
	std::cout << *zaz << std::endl;
	std::cout << *a << std::endl;
	zaz->equip(pr);
	std::cout << *zaz << std::endl;
	std::cout << *a << std::endl;
	zaz->attack(a);
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	std::cout << *a << std::endl;
		zaz->attack(a);
	// std::cout << *a << std::endl;
	// 	zaz->attack(a);
	// std::cout << *a << std::endl;
	// 	zaz->attack(a);
	// std::cout << *a << std::endl;
	// 	zaz->attack(a);
	
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
	std::cout << *b << std::endl;
	zaz->attack(b);
	std::cout << *b << std::endl;
	zaz->equip(pf);
	std::cout << *zaz << std::endl;
	zaz->attack(b);
	std::cout << *b << std::endl;
	zaz->attack(b);

	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();

	zaz->equip(sg);
	std::cout << *zaz << std::endl;
	std::cout << *dan << std::endl;
	zaz->attack(dan);
	
	zaz->equip(k);
	std::cout << *zaz << std::endl;
	std::cout << *bear << std::endl;
	zaz->attack(bear);
	std::cout << *bear << std::endl;
	zaz->attack(bear);
	std::cout << *bear << std::endl;
	zaz->attack(bear);
	std::cout << *bear << std::endl;
	zaz->attack(bear);
	

	std::cout << *zaz << std::endl;
	delete zaz;
	// delete dan;
	// delete bear;
	// delete pr;
	// delete pf;
	// delete sg;
	// delete k;
	return 0;
}
