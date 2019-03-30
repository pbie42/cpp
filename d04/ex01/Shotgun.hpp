/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shotgun.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:14:37 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:44:32 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOTGUN_H
#define SHOTGUN_H

#include <iostream>
#include <string>

#include "AWeapon.hpp"

class Shotgun : public AWeapon
{
	private:
		/* data */
	public:
		Shotgun(/* args */);
		Shotgun(Shotgun const &f);
		~Shotgun();
		Shotgun & operator=(Shotgun const &rhs);
		void attack() const;
};

#endif // SHOTGUN_H
