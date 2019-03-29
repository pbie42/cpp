/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:49:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 22:39:52 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(/* args */)
{
}

Character::Character(std::string name) :
slots(0),
name(name)
{
	this->materia[0] = NULL;
	this->materia[1] = NULL;
	this->materia[2] = NULL;
	this->materia[3] = NULL;
}

Character::Character(const Character &f)
{
	std::cout << "Copy constructor called" << std::endl;

	this->deleteMateria();
	for(int i = 0; i < f.getSlots(); i++)
	{
		if (f.getMateria(i) != NULL)
			this->materia[i] = f.getMateria(i);
	}
	this->slots = f.getSlots();
	*this = f;
}

Character::~Character()
{
	this->deleteMateria();
}

void Character::equip(AMateria *m)
{
	if (this->slots + 1 <= 4)
	{
		int x = 0;
		while(this->materia[x] != NULL)
			x++;
			std::cout << "equipping materia " << m->getType() << " in slot " << x << std::endl;
		this->materia[x] = m;
		this->slots++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 4)
	{
		std::cout << "unequipping materia " << this->materia[idx]->getType() << " in slot " << idx << std::endl;
		this->materia[idx] = NULL;
		this->slots--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4)
	{
		if (this->materia[idx] != NULL)
			this->materia[idx]->AMateria::use(target);
	}
}

Character & Character::operator=(Character const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->deleteMateria();
		for(int i = 0; i < rhs.getSlots(); i++)
		{
			if (rhs.getMateria(i) != NULL)
				this->materia[i] = rhs.getMateria(i);
		}
		this->slots = rhs.getSlots();
	}
	return *this;
}

void Character::deleteMateria()
{
	for(int i = 0; i < this->slots; i++)
	{
		if (this->materia[i] != NULL)
		{
			std::cout << "deleting materia " << this->materia[i]->getType() << std::endl;
			delete this->materia[i];
			this->materia[i] = NULL;
		}
	}
}

int Character::getSlots() const
{
	return this->slots;
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 4)
	{
		return this->materia[idx];
	}
	return NULL;
}

std::string const &Character::getName() const
{
	return this->name;
}
