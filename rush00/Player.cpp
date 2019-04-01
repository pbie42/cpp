/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 10:03:02 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 20:48:14 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(/* args */) :
_x(40),
_y(16),
_dispChar('o')
{
}

Player::Player(const Player &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Player::~Player()
{
}

Player & Player::operator=(Player const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

void Player::update(WINDOW *win, int tick)
{
	mvwaddch(win, this->getY(), this->getX(), this->getDispChar());
	wattron(win, A_ALTCHARSET);
	mvwaddch(win, this->getY(), this->getX() - 1, ACS_LARROW);
	mvwaddch(win, this->getY(), this->getX() + 1, ACS_RARROW);

	if((tick % 10) / 3) {
		wattron(win, COLOR_PAIR(tick % 2 ? 3 : 4));
		mvwaddch(win, this->getY() + 1, this->getX(), ACS_UARROW);
		wattroff(win, COLOR_PAIR(tick % 2 ? 3 : 4));
	}

	wattroff(win, A_ALTCHARSET);
}

int Player::getX() const
{
	return this->_x;
}

int Player::getY() const
{
	return this->_y;
}

char Player::getDispChar() const
{
	return this->_dispChar;
}

void Player::setX(int x)
{
	this->_x = x;
}

void Player::setY(int y)
{
	this->_y = y;
}

void Player::setDispChar(char c)
{
	this->_dispChar = c;
}

int Player::getLeft() const
{
	return this->_left;
}
int Player::getTop() const
{
	return this->_top;
}
int Player::getRight() const
{
	return this->_right;
}
int Player::getBottom() const
{
	return this->_bottom;
}

void Player::setLeft(int left)
{
	this->_left = left;
}
void Player::setTop(int top)
{
	this->_top = top;
}
void Player::setRight(int right)
{
	this->_right = right;
}
void Player::setBottom(int bottom)
{
	this->_bottom = bottom;
}

void Player::setBounds(int left, int right, int top, int bottom)
{
	this->setRight(right);
	this->setLeft(left);
	this->setTop(top);
	this->setBottom(bottom);
}
