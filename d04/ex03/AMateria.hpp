/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:20:20 by pbie              #+#    #+#             */
/*   Updated: 2019/03/29 21:54:22 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		/* data */
		AMateria(/* args */);
	protected:
		/* data */
		unsigned int xp_;
		std::string type;
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &f);
		virtual ~AMateria();
		AMateria & operator=(AMateria const &rhs);
		std::string const & getType() const;
		unsigned int getXP() const;
		void increaseXP();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_H
