/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Knife.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:14:37 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:46:21 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNIFE_H
#define KNIFE_H

#include <iostream>
#include <string>

#include "AWeapon.hpp"

class Knife : public AWeapon
{
	private:
		/* data */
	public:
		Knife(/* args */);
		Knife(Knife const &f);
		~Knife();
		Knife & operator=(Knife const &rhs);
		void attack() const;
};

#endif // KNIFE_H
