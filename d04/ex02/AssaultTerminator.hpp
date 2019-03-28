/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:25:19 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 21:59:52 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_H
#define ASSAULTTERMINATOR_H

#include <iostream>
#include <string>

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
	private:
		/* data */
	protected:
		/* data */
	public:
		AssaultTerminator(/* args */);
		AssaultTerminator(AssaultTerminator const &f);
		virtual ~AssaultTerminator();
		AssaultTerminator & operator=(AssaultTerminator const &rhs);
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

AssaultTerminator::AssaultTerminator(/* args */)
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

ISpaceMarine* AssaultTerminator::clone() const
{
	return new AssaultTerminator(*this);
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

#endif // ASSAULTTERMINATOR_H
