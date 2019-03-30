/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dan.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:44 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 21:01:16 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dan.hpp"

Dan::Dan(/* args */) : Enemy(40, "Dan")
{
	std::cout << "Hi I'm Daniel" << std::endl;
}

Dan::Dan(const Dan &f) : Enemy(40, "Dan")
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Dan::~Dan()
{
	std::cout << "I can't believe you've done this..." << std::endl;
}

Dan & Dan::operator=(Dan const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->setHP(rhs.getHP());
	this->type = rhs.getType();
	return *this;
}
