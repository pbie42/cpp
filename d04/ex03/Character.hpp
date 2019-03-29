/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:00:21 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 19:00:49 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class Character : ICharacter
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Character(/* args */);
		Character(Character const &f);
		virtual ~Character();
		Character & operator=(Character const &rhs);
};

Character::Character(/* args */)
{
}

Character::Character(const Character &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Character::~Character()
{
}

Character & Character::operator=(Character const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

#endif // CHARACTER_H
