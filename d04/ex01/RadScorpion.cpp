/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:44 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:43:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(/* args */) : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &f) : Enemy(80, "RadScorpion")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPORTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setHP(rhs.getHP());
	this->type = rhs.getType();
	return *this;
}
