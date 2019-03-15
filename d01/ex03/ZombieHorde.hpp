/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:43 by pbie              #+#    #+#             */
/*   Updated: 2019/03/15 11:15:39 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HORDE_H
#define ZOMBIE_HORDE_H

#include "Zombie.hpp"
#include <string>

class ZombieHorde
{
private:
	Zombie* zombies;
	int numOfZombies;
public:
	ZombieHorde(int n);
	~ZombieHorde();
	void announce(void);
};


#endif // ZOMBIE_HORDE_H
