/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:45:29 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 16:35:42 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(/* args */) : FragTrap("Standard SuperTrap"), NinjaTrap("Standard SuperTrap")
{
	std::cout << "SUPER-TP named <" << this->getName() << "> created!" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : FragTrap(name), NinjaTrap(name)
{
	std::cout << "SUPER-TP named <" << this->getName() << "> created!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

SuperTrap::~SuperTrap()
{
	std::cout << "SUPER-TP named <" << this->getName() << "> destroyed!" << std::endl;
}

void SuperTrap::rangedAttack(std::string const & target) const
{
	std::cout << "SUPER-TP named " << "<" << this->getName() << "> uses ";
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SUPER-TP named " << "<" << this->getName() << "> uses ";
	NinjaTrap::meleeAttack(target);
}
