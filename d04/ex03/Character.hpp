/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:00:21 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 22:24:17 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		/* data */
		AMateria* materia[4];
		int slots;
		std::string name;
		Character(/* args */);
	protected:
		/* data */
	public:
		Character(std::string name);
		Character(Character const &f);
		virtual ~Character();
		Character & operator=(Character const &rhs);
		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		AMateria *getMateria(int idx) const;
		virtual void use(int idx, ICharacter& target);
		int getSlots() const;
		void deleteMateria();
};

#endif // CHARACTER_H
