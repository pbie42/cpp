/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 09:46:59 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 22:58:08 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <ncurses.h>

#include "Window.hpp"
#include "Player.hpp"
#include "ObjectField.hpp"
#include "SpaceObject.hpp"

#define DOWN 1
#define UP -1

class Game
{
	private:
		/* data */
		Window *_mainWin;
		Window *_gameWin;
		Player *_player;
		ObjectField *_stars;
		ObjectField *_enemies;
		ObjectField *_asteroids;
		ObjectField *_enemyProjectiles;
		ObjectField *_playerProjectiles;
		int _left;
		int _right;
		int _top;
		int _bottom;
		int _left_g;
		int _right_g;
		int _top_g;
		int _bottom_g;
		int _score;
		bool _gameExit;
		bool _gameOver;
	protected:
		/* data */
	public:
		Game(/* args */);
		Game(Game const &f);
		virtual ~Game();
		Game & operator=(Game const &rhs);
		int init();
		void run();
		void close();
		Window *getMainWin() const;
		Window *getGameWin() const;
		int getPX() const;
		int getPY() const;
		char getPChar() const;
		void setPX(int);
		void setPY(int);
		void setPChar(char);
		void setLeft(int);
		void setRight(int);
		void setTop(int);
		void setBottom(int);
		void setBounds(int, int, int, int);
		void setGLeft(int);
		void setGRight(int);
		void setGTop(int);
		void setGBottom(int);
		void setGBounds(int, int, int, int);
		void initColorPairs();
		void enableKeysAndUnblocking();
		void drawMainWinBorder();
		void drawDivisionLine();
		void refreshWindows();
		void drawStars(int);
		void drawAsteroids(int);
		void drawEnemies(int);
		void drawPlayerProjectiles(int);
		void drawEnemyProjectiles(int);
		void playerMoveListen();
		void collisionChecks();
		int playerContinueListen();
};

#endif // GAME_H
