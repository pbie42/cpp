/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:39:56 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 16:18:58 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>

int main()
{
	ZombieEvent zombieEvent = ZombieEvent();
	std::cout << "You wake up and don't know where you are..." << std::endl;
	std::cout << "It turns out you are in the hospital but can't remember how you ended up there..." << std::endl;
	std::cout << "You realize you're all alone but can hear strange noises further down the hall..." << std::endl;
	std::cout << "You decide to investigate but are suddenly taken by surprise!\n" << std::endl;

	zombieEvent.setZombieType("Nurse");
	Zombie *claireZombie = zombieEvent.newZombie("Clair");
	claireZombie->announce();
	
	zombieEvent.setZombieType("Nurse");
	Zombie *corrineZombie = zombieEvent.newZombie("Corrine");
	claireZombie->announce();
	
	zombieEvent.setZombieType("Doctor");
	Zombie *dreZombie = zombieEvent.newZombie("Dre");
	dreZombie->announce();

	std::cout << "\nZombies out of nowhere! Luckily they move slowly." << std::endl;
	std::cout << "What's even luckier is that there is a gun nearby fully loaded." << std::endl;
	std::cout << "You decide to do two quick headshots" << std::endl;
	std::cout << "BANG! BANG!\n" << std::endl;
	delete claireZombie;
	delete corrineZombie;

	std::cout << "But now a bunch of random chumps are escaping their hospital beds!\n" << std::endl;

	zombieEvent.setZombieType("Patient");
	zombieEvent.randomChump();
	zombieEvent.randomChump();
	zombieEvent.randomChump();
	zombieEvent.randomChump();

	std::cout << "Another bit of luck! They are all too unhealthy to even stay reanimated and they've all died very quickly." << std::endl;
	std::cout << "But then you suddenly remember you had pretended to forget about Dr. Dre! Why do motherfuckers act like they forgot about Dre?" << std::endl;
	std::cout << "Good thing you have your AK. You shoot him dead." << std::endl;
	std::cout << "Bangabangabangabang!\n" << std::endl;

	delete dreZombie;

	std::cout << "And then you wake up! Whew it was just a dream" << std::endl;

	return 0;
}
