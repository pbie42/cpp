/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:43 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 15:28:23 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_EVENT_H
#define ZOMBIE_EVENT_H

#include "Zombie.hpp"
#include <string>

class ZombieEvent
{
private:
	std::string type;
public:
	ZombieEvent();
	~ZombieEvent();
	void setZombieType(std::string type);
	Zombie *newZombie(std::string name);
	void randomChump(void);
};


#endif // ZOMBIE_EVENT_H
