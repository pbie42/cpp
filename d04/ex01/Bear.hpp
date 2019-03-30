/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bear.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:52 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:47:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEAR_H
#define BEAR_H

#include "Enemy.hpp"

class Bear : public Enemy
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Bear(/* args */);
		Bear(Bear const &f);
		virtual ~Bear();
		Bear & operator=(Bear const &rhs);
};

#endif // BEAR_H
