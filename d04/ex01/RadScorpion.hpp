/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:52 by pbie              #+#    #+#             */
/*   Updated: 2019/03/28 16:07:23 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_H
#define RADSCORPION_H

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:
		/* data */
	protected:
		/* data */
	public:
		RadScorpion(/* args */);
		RadScorpion(RadScorpion const &f);
		virtual ~RadScorpion();
		RadScorpion & operator=(RadScorpion const &rhs);
};

#endif // RADSCORPION_H
