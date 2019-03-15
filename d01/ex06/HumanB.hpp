/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:46:36 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 16:32:48 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanB(std::string n);
	~HumanB();
	void attack(void);
	void setWeapon(Weapon& w);
};


#endif // HUMAN_B_H
