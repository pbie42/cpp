/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:05:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 21:40:24 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(/* args */) :
marineCount(0)
{
	int x = 0;
	while(x < 42){
		this->squad[x] = NULL;
		x++;
	}
}

Squad::Squad(const Squad &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->deleteSquad();
	int x = 0;
	while(x < this->getCount())
	{
		this->squad[x] = NULL;
		x++;
	}
	for(int i = 0; i < f.getCount(); i++)
	{
		if (f.getUnit(i) != NULL)
			this->squad[i] = f.getUnit(i)->clone();
	}
	this->marineCount = f.getCount();
	*this = f;
}

Squad::~Squad()
{
	std::cout << "Killing off squad" << std::endl;
	this->deleteSquad();
}

Squad & Squad::operator=(Squad const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->deleteSquad();
		int x = 0;
		while(x < this->getCount())
		{
			this->squad[x] = NULL;
			x++;
		}
		for(int i = 0; i < rhs.getCount(); i++)
		{
			if (rhs.getUnit(i) != NULL)
				this->squad[i] = rhs.getUnit(i)->clone();
		}
		this->marineCount = rhs.getCount();
	}
	return *this;
}

void Squad::deleteSquad()
{
	std::cout << "count: " << this->getCount() << std::endl;
	for(int i = 0; i < this->getCount(); i++)
	{
		std::cout << "here" << std::endl;
		if (this->squad[i] != NULL)
		{
			std::cout << "in here" << std::endl;
			delete this->squad[i];
		}
	}
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
