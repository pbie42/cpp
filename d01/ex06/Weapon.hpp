/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:41:50 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 14:52:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	Weapon();
	~Weapon();
	const std::string &getType(void) const;
	void setType(std::string type);
};


#endif // WEAPON_H
