/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 21:25:19 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 21:33:02 by pbie             ###   ########.fr       */
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
		std::string type;
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
		std::string getType() const;
};

#endif // ASSAULTTERMINATOR_H
