/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:09:07 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:35:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <sstream>

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	private:
		Character(/* args */);
	protected:
		/* data */
		std::string name;
		int ap;
		AWeapon *weapon;
	public:
		Character(std::string const & name);
		Character(Character const &f);
		virtual ~Character();
		Character & operator=(Character const &rhs);
		void recoverAP();
		void equip(AWeapon *);
		void attack(Enemy *);
		std::string const &getName() const;
		int getAP() const;
		AWeapon *getWeapon() const;
		void setAP(int ap);
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif // CHARACTER_H
