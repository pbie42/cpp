/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceObject.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 10:36:10 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 17:17:38 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <iostream>
#include <string>

#include "Entity.hpp"

class SpaceObject : public Entity
{
	private:
		/* data */
	protected:
		/* data */
	public:
		SpaceObject(int, int, int, bool);
		SpaceObject(SpaceObject const &f);
		SpaceObject();
		virtual ~SpaceObject();
		SpaceObject & operator=(SpaceObject const &rhs);
		void update();
		void setX(int);
		void setY(int);
		void setPos(int, int);
};

#endif // SPACEOBJECT_H
