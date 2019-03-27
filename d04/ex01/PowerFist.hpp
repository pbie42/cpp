/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 23:14:37 by pbie              #+#    #+#             */
/*   Updated: 2019/03/27 23:27:42 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_H
#define POWERFIST_H

#include <iostream>
#include <string>

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
	private:
		/* data */
	public:
		PowerFist(/* args */);
		PowerFist(PowerFist const &f);
		~PowerFist();
		PowerFist & operator=(PowerFist const &rhs);
		void attack() const;
};

#endif // POWERFIST_H
