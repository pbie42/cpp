/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:43 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 16:56:01 by pbie             ###   ########.fr       */
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
public:
	ZombieHorde(int n);
	~ZombieHorde();
	void setZombieType(std::string type);
	Zombie *newZombie(std::string name);
	void randomChump(void);
};


#endif // ZOMBIE_HORDE_H
