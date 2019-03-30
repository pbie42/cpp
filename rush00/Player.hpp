/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:51:57 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 17:56:17 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <ncurses.h>

class Player
{
	private:
		Player(/* args */);
		int xLoc;
		int yLoc;
		int xMax;
		int yMax;
		char character;
		WINDOW *curWin;
	protected:
		/* data */
	public:
		Player(WINDOW *win, int y, int x, char c);
		Player(Player const &f);
		virtual ~Player();
		Player & operator=(Player const &rhs);
		void mvUp();
		void mvDown();
		void mvLeft();
		void mvRight();
		void display();
		int getMv();
};

Player::Player(/* args */)
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

#endif // PLAYER_H
