/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:03:25 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 22:33:41 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
#define SQUAD_H

#include <iostream>
#include <string>

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	private:
		/* data */
	protected:
		ISpaceMarine* squad[42];
		int marineCount;
	public:
		Squad(/* args */);
		Squad(Squad const &f);
		virtual ~Squad();
		Squad & operator=(Squad const &rhs);
		int getCount() const;
		ISpaceMarine* getUnit(int) const;
		int push(ISpaceMarine*);
};

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
}

Squad & Squad::operator=(Squad const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
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

	if (marine == NULL) return;
	while(x < count)
	{
		if (marine == this->squad[x]) return;
		x++;
	}
	this->squad[count] = marine;
	this->marineCount++;
}

#endif // SQUAD_H
