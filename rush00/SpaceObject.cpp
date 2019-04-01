/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceObject.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 11:17:28 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 17:17:56 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceObject.hpp"

#include <string>

SpaceObject::SpaceObject(int x, int y, int dir, bool canShoot)
{
	_x = x;
	_y = y;
	_dir = dir;
	_canShoot = canShoot;
}

SpaceObject::SpaceObject()
{
	_x = -1;
	_y = -1;
	_dir = 0;
	_canShoot = false;
	_maxx = -1;
	_maxy = -1;
}

SpaceObject::SpaceObject(const SpaceObject &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

SpaceObject::~SpaceObject()
{
	
}

SpaceObject & SpaceObject::operator=(SpaceObject const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void SpaceObject::update()
{
	this->setY(this->getY() + _dir);
}
void SpaceObject::setX(int x)
{
	this->_x = x;
}
void SpaceObject::setY(int y)
{
	this->_y = y;
}
void SpaceObject::setPos(int y, int x)
{
	this->setY(y);
	this->setX(x);
}
