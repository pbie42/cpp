/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:05:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 11:31:29 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(/* args */) :
marineCount(0)
{
}

Squad::Squad(const Squad &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Squad::~Squad()
{
	for(int i = 0; i < this->getCount(); i++)
	{
		delete this->squad[i];
	}
}

Squad & Squad::operator=(Squad const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for(int i = 0; i < this->getCount(); i++)
		{
			delete this->squad[i];
		}
		for(int i = 0; i < rhs.getCount(); i++)
		{
			this->squad[i] = rhs.getUnit(i);
		}
	}
	return *this;
}

int Squad::getCount() const
{
	return this->marineCount;
}

ISpaceMarine *Squad::getUnit(int n) const
{
	if (n > this->getCount()) return NULL;
	return this->squad[n];
}

int Squad::push(ISpaceMarine *marine)
{
	int x = 0;
	int count = this->getCount();

	if (marine == NULL) return -1;
	while(x < count)
	{
		if (marine == this->squad[x]) return -1;
		x++;
	}
	this->squad[x] = marine;
	this->marineCount++;
	return x;
}
