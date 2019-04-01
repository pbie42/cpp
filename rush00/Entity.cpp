#include "Entity.hpp"
#include <cstring>

Entity::Entity()
{
	
}

Entity::~Entity()
{
}

Entity::Entity(const Entity &s)
{
	*this = s;
	
}

Entity &Entity::operator=(const Entity &s)
{
	_pattern = s._pattern;
	_maxx = s._maxx;
	_maxy = s._maxy;

	// _width = s._width;
	// _height = s._height;

	_x = s._x;
	_y = s._y;
	return *this;
}

// void Entity::movex(int x)
// {
// 	if (x < 0 && _x + x < 1)
// 		_x = 1;
// 	// minus 1, it starts at 0
// 	else if (x > 0 && _x + x >= (_maxx - 1))
// 	// minus 2, we want it before the border, not on the border
// 		_x = _maxx - 2;
// 	else
// 		_x += x;
// }

// void Entity::movey(int y)
// {
// 	// explaination same as movex
// 	if (y < 0 && _y + y < 1)
// 		_y = 1;
// 	else if (y > 0 && _y + y >= (_maxy - 1))
// 		_y = _maxy - 2;
// 	else
// 		_y += y;
// }

int Entity::getX() const
{
	return _x;
}

int Entity::getY() const
{
	return _y;
}

const std::string &Entity::getPattern() const
{
	return _pattern;
}

// void Entity::setIDX(int idx)
// {
// 	_idx = idx;
// }

// int Entity::getIDX()
// {
// 	return _idx;
// }

int Entity::getWidth() const
{
	return _maxx;
}

int Entity::getHeight() const
{
	return _maxy;
}

int Entity::getLeft() const
{
	return _left;
}
int Entity::getRight() const
{
	return _right;
}
int Entity::getTop() const
{
	return _top;
}
int Entity::getBottom() const
{
	return _bottom;
}
void Entity::setLeft(int left)
{
	_left = left;
}
void Entity::setRight(int right)
{
	_right = right;
}
void Entity::setTop(int top)
{
	_top = top;
}
void Entity::setBottom(int bottom)
{
	_bottom = bottom;
}

bool Entity::canShoot()
{
	return _canShoot;
}

void Entity::setIDX(int idx)
{
	_idx = idx;
}

int Entity::getIDX()
{
	return _idx;
}

