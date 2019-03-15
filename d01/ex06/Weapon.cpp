/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:41:45 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:52:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
	this->type = "Stick";
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
