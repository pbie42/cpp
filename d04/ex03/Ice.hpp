/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:48:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 18:54:27 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Ice(/* args */);
		Ice(Ice const &f);
		virtual ~Ice();
		Ice & operator=(Ice const &rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif // ICE_H
