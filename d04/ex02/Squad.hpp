/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:03:25 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 12:00:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_H
#define SQUAD_H

#include <iostream>
#include <string>

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
	private:
		/* data */
	protected:
		ISpaceMarine* squad[42];
		int marineCount;
	public:
		Squad(/* args */);
		Squad(Squad const &f);
		virtual ~Squad();
		Squad & operator=(Squad const &rhs);
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
};

#endif // SQUAD_H
