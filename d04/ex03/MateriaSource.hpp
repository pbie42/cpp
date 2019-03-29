/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:02:07 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 22:31:50 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* materia[4];
		int slots;
	protected:
		/* data */
	public:
		MateriaSource(/* args */);
		MateriaSource(MateriaSource const &f);
		virtual ~MateriaSource();
		MateriaSource & operator=(MateriaSource const &rhs);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

MateriaSource::MateriaSource(/* args */) :
slots(0)
{
	this->materia[0] = NULL;
	this->materia[1] = NULL;
	this->materia[2] = NULL;
	this->materia[3] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->slots + 1 <= 4)
	{
		int x = 0;
		while(this->materia[x] != NULL)
			x++;
		std::cout << "learning materia " << m->getType() << " in slot " << x << std::endl;
		this->materia[x] = m;
		this->slots++;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	if (type.compare("ice") == 0)
	{
		std::cout << "creating ice" << std::endl;
		int x = 0;
		while(x < this->slots)
		{
			if (this->materia[x]->getType().compare(type) == 0)
			{
				std::cout << "returning new ice" << std::endl;
				return new Ice();
			}
			x++;
		}
	}
	if (type.compare("cure") == 0)
	{
		std::cout << "creating cure" << std::endl;
		int x = 0;
		while(x < this->slots)
		{
			if (this->materia[x]->getType().compare(type) == 0)
			{
				std::cout << "returning new cure" << std::endl;
				return new Cure();
			}
			x++;
		}
	}
	return NULL;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

#endif // MATERIASOURCE_H
