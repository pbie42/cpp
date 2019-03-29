/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:48:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 18:53:55 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <iostream>
#include <string>

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Cure(/* args */);
		Cure(Cure const &f);
		virtual ~Cure();
		Cure & operator=(Cure const &rhs);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif // CURE_H
