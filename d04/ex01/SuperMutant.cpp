/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:44 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:43:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(/* args */) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &f) : Enemy(170, "Super Mutant")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int dmg)
{
	Enemy::takeDamage(dmg - 3);
}

SuperMutant & SuperMutant::operator=(SuperMutant const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setHP(rhs.getHP());
	this->type = rhs.getType();
	return *this;
}
