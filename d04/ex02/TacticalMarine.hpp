/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:25:19 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 21:32:54 by pbie             ###   ########.fr       */
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
		std::string type;
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
		std::string getType() const;
};

#endif // TACTICALMARINE_H
