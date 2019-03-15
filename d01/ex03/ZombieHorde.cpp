/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:06:09 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 11:24:07 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <ctime>

ZombieHorde::ZombieHorde(int n)
{
	this->zombies = new Zombie[n];
	this->numOfZombies = n;

	std::cout << "\nThe Zombie Horde has been created\n" << std::endl;
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->zombies;
	std::cout << "\nThe Zombie Horde has been eliminated" << std::endl;
}

void ZombieHorde::announce(void)
{
	int x = 0;

	while(x < this->numOfZombies){
		this->zombies[x].announce();
		x++;
	}
}


