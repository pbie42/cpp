/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:42:40 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 16:08:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(/* args */);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	virtual ~FragTrap();
	FragTrap & operator=(FragTrap const &rhs);
	void vaulthunter_dot_exe(std::string const & target);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif // FRAGTRAP_H
