/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:06:09 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 16:17:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <ctime>

ZombieEvent::ZombieEvent(/* args */)
{
	this->type = "Normal";
	std::cout << "The Zombie apocalypse has begun\n" << std::endl;
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "\nThe Zombie apocalypse has ended" << std::endl;
}

void ZombieEvent::setZombieType(std::string type)
{
	this->type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name, this->type);
	return newZombie;
}

void ZombieEvent::randomChump()
{
	std::string randomNames[8] = { "Paul", "Jennifer", "Nick", "Josie", "Michael", "Rachael", "Matt", "Adrien"};
	srand(time(0) + rand());
	int random = rand() % 8;

	Zombie newZombie = Zombie(randomNames[random], this->type);
	newZombie.announce();
}


