/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 22:28:29 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 14:52:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_H
#define AWEAPON_H

#include <string>
#include <iostream>

class AWeapon
{
	private:
		/* data */
		AWeapon();
	protected:
		std::string name;
		int apcost;
		int damage;
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const &f);
		virtual ~AWeapon();
		int getAPCost() const;
		int getDamage() const;
		void setAPCost(int apcost);
		void setDamage(int damage);
		std::string const &getName() const;
		virtual void attack() const = 0;
		AWeapon & operator=(AWeapon const &rhs);
};

#endif // AWEAPON_H
