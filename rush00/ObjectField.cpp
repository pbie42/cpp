/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObjectField.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 11:17:08 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 22:36:29 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObjectField.hpp"

ObjectField::ObjectField(/* args */) :
_pattern("V"),
_colorPair(1)
{
	_canShoot = false;
	_doesSpawn = false;
	_dir = 1;
	_objCount = 0;
	_maxObj = 16;
	_maxx = 1;
	_maxy = 1;
	_obj = new SpaceObject*[_maxObj];
}

ObjectField::ObjectField(const std::string &_p, int maxx, int maxy,
					int colorPair, int dir, bool canShoot, bool doesSpawn) :
_colorPair(colorPair)
{
	_canShoot = canShoot;
	_doesSpawn = doesSpawn;
	_dir = dir;
	_objCount = 0;
	_maxObj = 16;
	_obj = new SpaceObject*[_maxObj];
	// _pattern size
	_pattern = _p;
	_maxx = maxx; // in width
	_maxy = maxy; // in height
}

ObjectField::ObjectField(const ObjectField &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

ObjectField::~ObjectField()
{
	int i;

	for (i = 0; i < _objCount; i++)
	{
		delete _obj[i];
		_obj[i] = (SpaceObject *)-1;
	}
	for (; i <_objCount; i++)
	{
		_obj[i] = (SpaceObject *)-1;
	}
	_canShoot = false;
	_doesSpawn = false;
	_dir = 0;
	_objCount = -1;
	_maxObj = -1;
	delete[] _obj;
}

ObjectField & ObjectField::operator=(ObjectField const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_canShoot = rhs._canShoot;
		_dir = rhs._dir;
		_objCount = rhs._objCount;
		_maxObj = rhs._maxObj;
		_obj = rhs._obj;
	}
	return *this;
}

bool ObjectField::collisionCheck(Player *p)
{
	for(int i = 0; i < this->_maxObj; i++)
	{
		if (this->_obj[i] != NULL)
		{
			int x = this->_obj[i]->getX();
			int y = this->_obj[i]->getY();
			for(int j = 0; j < _maxx; j++)
			{
				if ((x + j == p->getX() && y == p->getY())
				|| (x + j == p->getX() - 1 && y == p->getY())
				|| (x + j == p->getX() + 1 && y == p->getY()))
				{
					this->destroyObject(i);
					return true;
				}
			}
		}
	}
	return false;
}



bool ObjectField::collisionCheck(SpaceObject *p, int maxx)
{
	for(int i = 0; i < this->_maxObj; i++)
	{
		if (this->_obj[i] != NULL)
		{
			int x = this->_obj[i]->getX();
			int y = this->_obj[i]->getY();
			for(int j = 0; j < maxx; j++)
			{
				if ((x == p->getX() + j && y == p->getY()))
				{
					this->destroyObject(i);
					return true;
				}
			}
		}
	}
	return false;
}

void ObjectField::update()
{
	srand(time(0) + rand());
	for (int i = 0; i < this->_maxObj; i++)
	{
		if (this->_obj[i] != NULL && this->_obj[i]->getY() > this->_bottom)
		{
			this->destroyObject(i);
		}
		else if (this->_obj[i] != NULL)
		{
			this->_obj[i]->update();
		}
	}
	if (_doesSpawn && this->_objCount < this->_maxObj)
	{

		int z = (rand() % this->_right);
		z = z + (z >= 38 ? -2 : 2);
		SpaceObject *s = new SpaceObject(z, 0, _dir, _canShoot);
		this->addObject(s);
	}
}

void ObjectField::clearPos(WINDOW *win)
{
	for(int i = 0; i < this->_maxObj; i++)
	{
		if (this->_obj[i] != NULL)
		{
			mvwaddch(win, 2, 2, 'y');
			mvwaddch(win, this->_obj[i]->getY(), this->_obj[i]->getX(), ' ');
		}
	}
	
}

void ObjectField::printPos(WINDOW *win)
{
	for(int i = 0; i < _objCount; i++)
	{
		wattron(win, COLOR_PAIR(this->_colorPair));
		for (int z = 0; z < _maxy; z++)
		{
			mvwprintw(win, _obj[i]->getY() + z, _obj[i]->getX(), "%*s",
				_maxx, _pattern.c_str());
		}
		wattroff(win, COLOR_PAIR(_colorPair));
	}
}

void ObjectField::setBounds(int left, int right, int top, int bottom)
{
	this->setRight(right);
	this->setLeft(left);
	this->setTop(top);
	this->setBottom(bottom);
}

void ObjectField::addObject(SpaceObject *obj)
{
	if (_objCount >= _maxObj)
	{
		SpaceObject **ara = _obj;
		int i;

		_obj = new SpaceObject*[_maxObj * 2];
		for (i = 0; i < _maxObj; i++)
			_obj[i] = ara[i];
		delete[] ara;
		_maxObj *= 2;
		for (; i < _maxObj; i++)
			_obj[i] = 0;
	}
	obj->setIDX(_objCount);
	_obj[_objCount++] = obj;
}
void ObjectField::destroyObject(int idx)
{
	if (idx >= _objCount)
		return ;
	delete _obj[idx];
	_obj[idx] = _obj[--_objCount];
	_obj[idx]->setIDX(idx);
	_obj[_objCount] = 0;
}

SpaceObject* ObjectField::getObj(int idx) const
{
	return _obj[idx];
}

int ObjectField::getObjCount() const
{
	return _objCount;
}

int ObjectField::getMaxX() const
{
	return _maxx;
}
