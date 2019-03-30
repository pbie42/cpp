/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:42:41 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 18:47:45 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(/* args */)
{
}

Player::Player(WINDOW *win, int y, int x, char c)
{
	this->curWin = win;
	this->xLoc = x;
	this->yLoc = y;
	getmaxyx(this->curWin, this->yMax, this->xMax);
	keypad(curWin, true);
	this->character = c;
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
		this->curWin = rhs.getCurWin();
		this->xLoc = rhs.getXLoc();
		this->yLoc = rhs.getYLoc();
		this->yMax = rhs.getYMax();
		this->xMax = rhs.getXMax();
		keypad(curWin, true);
		this->character = rhs.getCharacter();
	}
	return *this;
}

void Player::mvUp()
{
	this->clear();
	this->yLoc--;
	if (this->yLoc < 1)
		this->yLoc = 1;
}
void Player::mvDown()
{
	this->clear();
	this->yLoc++;
	if (this->yLoc > this->yMax - 2)
		this->yLoc = this->yMax - 2;
}
void Player::mvLeft()
{
	this->clear();
	this->xLoc--;
	if (this->xLoc < 1)
		this->xLoc = 1;
}
void Player::mvRight()
{
	this->clear();
	this->xLoc++;
	if (this->xLoc > this->xMax - 2)
		this->xLoc = this->xMax - 2;
}

void Player::clear()
{
	mvwaddch(this->curWin, this->yLoc, this->xLoc, ' ');
}

int Player::getMv()
{
	int choice = wgetch(this->curWin);
	switch (choice)
	{
		case KEY_UP:
			this->mvUp();
			break;
		case KEY_DOWN:
			this->mvDown();
			break;
		case KEY_LEFT:
			this->mvLeft();
			break;
		case KEY_RIGHT:
			this->mvRight();
			break;
	
		default:
			break;
	}
	return choice;
}

void Player::display()
{
	mvwaddch(this->curWin, this->yLoc, this->xLoc, this->character);
}

int Player::getXLoc() const
{
	return this->xLoc;
}
int Player::getYLoc() const
{
	return this->yLoc;
}
int Player::getXMax() const
{
	return this->xMax;
}
int Player::getYMax() const
{
	return this->yMax;
}
char Player::getCharacter() const
{
	return this->character;
}
WINDOW *Player::getCurWin() const
{
	return this->curWin;
}
