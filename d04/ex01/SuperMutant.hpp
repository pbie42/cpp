/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:52 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:06:16 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_H
#define SUPERMUTANT_H

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:
		/* data */
	protected:
		/* data */
	public:
		SuperMutant(/* args */);
		SuperMutant(SuperMutant const &f);
		virtual ~SuperMutant();
		SuperMutant & operator=(SuperMutant const &rhs);
		void takeDamage(int);
};

#endif // SUPERMUTANT_H
