/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:10:32 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 16:08:36 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_H
#define NINJATRAP_H

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

class NinjaTrap : public ClapTrap
{
private:
	/* data */
public:
	NinjaTrap(/* args */);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &f);
	virtual ~NinjaTrap();
	NinjaTrap & operator=(NinjaTrap const &rhs);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void ninjaShoebox(FragTrap & target) const;
	void ninjaShoebox(ScavTrap & target) const;
	void ninjaShoebox(ClapTrap & target) const;
	void ninjaShoebox(NinjaTrap & target) const;
};


#endif // NINJATRAP_H
