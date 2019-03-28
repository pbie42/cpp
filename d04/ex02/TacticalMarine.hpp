/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:25:19 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 21:59:05 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_H
#define TACTICALMARINE_H

#include <iostream>
#include <string>

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	private:
		/* data */
	protected:
		/* data */
	public:
		TacticalMarine(/* args */);
		TacticalMarine(TacticalMarine const &f);
		virtual ~TacticalMarine();
		TacticalMarine & operator=(TacticalMarine const &rhs);
		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;
};

TacticalMarine::TacticalMarine(/* args */)
{
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh..." << std::endl;
}

ISpaceMarine* TacticalMarine::clone() const
{
	return new TacticalMarine(*this);
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *" << std::endl;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

#endif // TACTICALMARINE_H
