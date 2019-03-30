/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:51:57 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 18:47:24 by pbie             ###   ########.fr       */
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
		void clear();
		int getMv();
		int getXLoc() const;
		int getYLoc() const;
		int getXMax() const;
		int getYMax() const;
		char getCharacter() const;
		WINDOW *getCurWin() const;
};
#endif // PLAYER_H
