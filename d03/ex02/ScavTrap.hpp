/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:23:26 by pbie              #+#    #+#             */
/*   Updated: 2019/03/26 12:00:46 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap(/* args */);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap & operator=(ScavTrap const &rhs);
	void challengeNewcomer() const;
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif // SCAVTRAP_H
