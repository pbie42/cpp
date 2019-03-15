/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:03:18 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 11:24:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string cName, std::string cType)
{
	this->name = cName;
	this->type = cType;
	std::cout << "Zombie " << this->name << " has reanimated" << std::endl;
}

Zombie::Zombie()
{
	std::string randomNames[8] = { "Paul", "Jennifer", "Nick", "Josie", "Michael", "Rachael", "Matt", "Adrien"};
	srand(time(0) + rand());
	int random = rand() % 8;

	this->name = randomNames[random];
	this->type = "Normal";

	std::cout << "Zombie " << this->name << " has reanimated" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is deader than dead now\n" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << "<" << this->name << " (" << this->type << ")>" << "Braaaaiiinnnnsssss....." << std::endl;
}
