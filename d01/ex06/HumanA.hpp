/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:46:36 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 16:24:44 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
#define HUMAN_A_H

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string name;
	Weapon &weapon;
public:
	HumanA(std::string n, Weapon& w);
	~HumanA();
	void attack(void);
};


#endif // HUMAN_A_H
