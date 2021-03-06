/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 10:01:34 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 14:33:23 by pbie             ###   ########.fr       */
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
		/* data */
		int _x;
		int _y;
		int _left;
		int _right;
		int _top;
		int _bottom;
		char _dispChar;
	protected:
		/* data */
	public:
		Player(/* args */);
		Player(Player const &f);
		virtual ~Player();
		Player & operator=(Player const &rhs);
		int getX() const;
		int getY() const;
		char getDispChar() const;
		void setX(int);
		void setY(int);
		void update(WINDOW *win, int tick);
		void move();
		void setDispChar(char);
		int getLeft() const;
		int getTop() const;
		int getRight() const;
		int getBottom() const;
		void setLeft(int);
		void setTop(int);
		void setRight(int);
		void setBottom(int);
		void setBounds(int, int, int, int);
};

#endif // PLAYER_H
