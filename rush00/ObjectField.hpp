/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectField.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 10:41:12 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 22:30:09 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTFIELD_H
#define OBJECTFIELD_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include "SpaceObject.hpp"
#include "Player.hpp"
#include "Entity.hpp"

class ObjectField : public Entity
{
	private:
		ObjectField(/* args */);
		bool _doesSpawn;
		SpaceObject** _obj;
		std::string _pattern;
		int _maxx;
		int _maxy;
		int _maxObj;
		int _objCount;
		int _colorPair;
	protected:
		/* data */
	public:
		ObjectField(const std::string &, int, int,
			int colorPair, int dir, bool canShoot, bool doesSpawn);
		ObjectField(ObjectField const &f);
		virtual ~ObjectField();
		ObjectField & operator=(ObjectField const &rhs);
		void update();
		void clearPos(WINDOW *win);
		void printPos(WINDOW *win);
		void erase(size_t);
		SpaceObject* getObj(int) const;
		void setBounds(int, int, int, int);
		bool collisionCheck(Player *p);
		bool collisionCheck(SpaceObject *p, int maxx);
		void addObject(SpaceObject *);
		void destroyObject(int);
		int getObjCount() const;
		int getMaxX() const;
};

#endif // OBJECTFIELD_H
