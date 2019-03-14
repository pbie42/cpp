/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:02:10 by pbie              #+#    #+#             */
/*   Updated: 2019/03/14 15:06:45 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
private:
	std::string type;
	std::string name;
public:
	Zombie(std::string cName, std::string cType);
	~Zombie();
	void announce(void);
};

#endif // ZOMBIE_H
