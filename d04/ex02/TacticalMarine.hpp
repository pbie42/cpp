/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:25:19 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 12:00:29 by pbie             ###   ########.fr       */
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
		virtual ISpaceMarine* clone() const;
		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
};

#endif // TACTICALMARINE_H
