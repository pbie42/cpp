/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:14:37 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 23:27:30 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_H
#define PLASMARIFLE_H

#include <iostream>
#include <string>

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
	private:
		/* data */
	public:
		PlasmaRifle(/* args */);
		PlasmaRifle(PlasmaRifle const &f);
		~PlasmaRifle();
		PlasmaRifle & operator=(PlasmaRifle const &rhs);
		void attack() const;
};

#endif // PLASMARIFLE_H
