/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dan.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:56:52 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 20:47:53 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAN_H
#define DAN_H

#include "Enemy.hpp"

class Dan : public Enemy
{
	private:
		/* data */
	protected:
		/* data */
	public:
		Dan(/* args */);
		Dan(Dan const &f);
		virtual ~Dan();
		Dan & operator=(Dan const &rhs);
};

#endif // DAN_H
