/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bear.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:44 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:50:25 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bear.hpp"

Bear::Bear(/* args */) : Enemy(70, "Bear")
{
	std::cout << "* ROARRRR *" << std::endl;
}

Bear::Bear(const Bear &f) : Enemy(70, "Bear")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Bear::~Bear()
{
	std::cout << "* ROARRRRrrrr.....*" << std::endl;
}

Bear & Bear::operator=(Bear const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setHP(rhs.getHP());
	this->type = rhs.getType();
	return *this;
}
