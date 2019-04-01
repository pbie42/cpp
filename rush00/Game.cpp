/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 09:48:11 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 23:05:02 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include <unistd.h>
#include <iostream>

Game::Game(/* args */) :
_player(new Player()),
_score(0),
_gameExit(false),
_gameOver(false)
{
	_stars = 0;
	_enemies = 0;
	_asteroids = 0;
	_enemyProjectiles = 0;
	_playerProjectiles = 0;
	_mainWin = 0;
	_gameWin = 0;
}

Game::Game(const Game &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Game::~Game()
{
	delete _stars;
	delete _enemies;
	delete _asteroids;
	delete _enemyProjectiles;
	delete _playerProjectiles;
	delete _gameWin;
	delete _mainWin;
	delete _player;
	endwin();
}

Game & Game::operator=(Game const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{

	}
	return *this;
}

int Game::init()
{
	this->_mainWin = new Window(initscr());
	cbreak();
	noecho();
	clear();
	refresh();
	curs_set(0);

	if(!has_colors()) {
		endwin();
		std::cerr << "No colors sorry :(" << std::endl;
		exit(1);
	}
	start_color();

	this->setBounds(0, 80, 0, 24);

	int infoPanelHeight = 4;
	this->_gameWin = new Window(newwin(
		this->_bottom - infoPanelHeight - 2,
		this->_right - 2,
		this->_top + 1,
		this->_left + 1
	));

	delete this->_mainWin;

	this->_mainWin = new Window(newwin(
		this->_bottom,
		this->_right,
		0,
		0
	));

	this->setGBounds(0, this->_right - 2, 0, this->_bottom - infoPanelHeight - 4);
	this->initColorPairs();
	this->enableKeysAndUnblocking();

	return 0;
}



void Game::run()
{
	int tick = 0;
	this->_stars = new ObjectField(".", 1, 1, 1, DOWN, false, true);
	this->_asteroids = new ObjectField("*", 1, 1, 4, DOWN, false, true);
	this->_playerProjectiles = new ObjectField("|", 1, 1, 2, UP, false, false);
	this->_enemies = new ObjectField("(+)", 3, 1, 3, DOWN, true, true);
	this->_enemyProjectiles = new ObjectField("|", 1, 1, 3, DOWN, false, false);
	this->_stars->setBounds(this->_left_g, this->_right_g, this->_top_g, this->_bottom_g);
	this->_playerProjectiles->setBounds(this->_left_g, this->_right_g, this->_top_g, this->_bottom_g);
	this->_enemyProjectiles->setBounds(this->_left_g, this->_right_g, this->_top_g, this->_bottom_g);
	this->_asteroids->setBounds(this->_left_g, this->_right_g, this->_top_g, this->_bottom_g);
	this->_enemies->setBounds(this->_left_g, this->_right_g, this->_top_g, this->_bottom_g);

	this->drawMainWinBorder();
	this->drawDivisionLine();
	this->refreshWindows();

	bool continuePlaying = true;
	while (continuePlaying)
	{
		werase(this->getGameWin()->getWin());
		
		this->playerMoveListen();

		this->drawStars(tick);
		this->drawAsteroids(tick);
		this->drawPlayerProjectiles(tick);
		this->drawEnemies(tick);
		this->drawEnemyProjectiles(tick);
		collisionChecks();
		this->_player->setBounds(this->getPX() - 1, 3, this->getPY(), 1);
		this->_player->update(this->getGameWin()->getWin(), tick);
		this->refreshWindows();

		if (this->_gameExit) break;
		if (this->_gameOver) {
			werase(this->getGameWin()->getWin());
			this->refreshWindows();
			while(continuePlaying)
			{
				int x = this->playerContinueListen();
				if (x == 2) continue;
				if (x == 1)
				{
					_gameOver = false;
					mvwprintw(this->getMainWin()->getWin(), 22, 40, "%33s", "");
					break;
				}
				if (x == 0)
				{
					continuePlaying = false;
				}
			}
		}
		if (!continuePlaying) break;

		wmove(this->getMainWin()->getWin(), this->_bottom - 3, 2);
		wprintw(this->getMainWin()->getWin(), "SCORE: %d", _score);
		move(0,0);

		tick++;

		usleep(10000);
	}
	usleep(10000);
}
void Game::close()
{
	endwin();
}

Window *Game::getMainWin() const
{
	return this->_mainWin;
}
Window *Game::getGameWin() const
{
	return this->_gameWin;
}

int Game::getPX() const
{
	return this->_player->getX();
}
int Game::getPY() const
{
	return this->_player->getY();
}
char Game::getPChar() const
{
	return this->_player->getDispChar();
}

void Game::setPX(int x)
{
	this->_player->setX(x);
}
void Game::setPY(int y)
{
	this->_player->setY(y);
}
void Game::setPChar(char c)
{
	this->_player->setDispChar(c);
}

void Game::setLeft(int left)
{
	this->_left = left;
}
void Game::setRight(int right)
{
	this->_right = right;
}
void Game::setTop(int top)
{
	this->_top = top;
}
void Game::setBottom(int bottom)
{
	this->_bottom = bottom;
}
void Game::setBounds(int left, int right, int top, int bottom)
{
	this->setRight(right);
	this->setLeft(left);
	this->setTop(top);
	this->setBottom(bottom);
}

void Game::setGLeft(int left)
{
	this->_left_g = left;
}
void Game::setGRight(int right)
{
	this->_right_g = right;
}
void Game::setGTop(int top)
{
	this->_top_g = top;
}
void Game::setGBottom(int bottom)
{
	this->_bottom_g = bottom;
}
void Game::setGBounds(int left, int right, int top, int bottom)
{
	this->setGRight(right);
	this->setGLeft(left);
	this->setGTop(top);
	this->setGBottom(bottom);
}

void Game::initColorPairs()
{
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
}

void Game::enableKeysAndUnblocking()
{
	// enable function keys
	keypad(this->_mainWin->getWin(), true);
	keypad(this->_gameWin->getWin(), true);

	// disable input blocking
	nodelay(this->_mainWin->getWin(), true);
	nodelay(this->_gameWin->getWin(), true);
}

void Game::drawMainWinBorder()
{
	wattron(this->getMainWin()->getWin(), A_BOLD);
	box(this->getMainWin()->getWin(), 0, 0);
	wattroff(this->getMainWin()->getWin(), A_BOLD);
}

void Game::drawDivisionLine()
{
	// draw dividing line between game and stats
	wmove(this->getMainWin()->getWin(), this->_bottom_g + 3, 1);
	whline(this->getMainWin()->getWin(), '-', this->_right - 2);
}

void Game::refreshWindows()
{
	wrefresh(this->getMainWin()->getWin());
	wrefresh(this->getGameWin()->getWin());
}

void Game::drawStars(int tick)
{
	if (tick % 7 == 0)
		this->_stars->update();
	this->_stars->printPos(this->getGameWin()->getWin());
}

void Game::drawPlayerProjectiles(int tick)
{
	if (tick % 15 == 0)
		this->_playerProjectiles->update();
	this->_playerProjectiles->printPos(this->getGameWin()->getWin());
}

void Game::drawAsteroids(int tick)
{
	if (tick > 100 && tick % 55 == 0)
		this->_asteroids->update();
	this->_asteroids->printPos(this->getGameWin()->getWin());
}

void Game::drawEnemyProjectiles(int tick)
{
	if (tick % 7 == 0)
		this->_enemyProjectiles->update();
	this->_enemyProjectiles->printPos(this->getGameWin()->getWin());
}

void Game::drawEnemies(int tick)
{
	if (tick > 100 && tick % 14 == 0)
		this->_enemies->update();
	this->_enemies->printPos(this->getGameWin()->getWin());
	// SHOOT ENEMY
	if (tick > 100 && tick % 21 == 0)
	{
		int count = _enemies->getObjCount();
		if (count)
		{
			SpaceObject *n = _enemies->getObj(rand() % count);
			_enemyProjectiles->addObject(new SpaceObject(n->getX() + 1, n->getY() + 1, DOWN, false));
		}
	}
}

int Game::playerContinueListen()
{
	int inChar = '@';
	inChar = wgetch(this->getMainWin()->getWin());
	inChar = tolower(inChar);
	if (inChar == ERR) inChar = '@';

	mvwprintw(this->getMainWin()->getWin(), 22, 40, "Press Y to Continue or N to quit");

	switch (inChar)
	{
		case 'y':
			return 1;
		case 'n':
			return 0;
		default:
			return 2;
	}
}

void Game::playerMoveListen()
{
	int inChar = '@';
	inChar = wgetch(this->getMainWin()->getWin());
	inChar = tolower(inChar);
	if (inChar == ERR) inChar = '@';

	switch (inChar)
	{
		case 'q':
			this->_gameExit = true;
			break;
		case KEY_UP:
		case 'w':
		case 'i':
			if (this->getPY() > this->_top_g)
				this->setPY(this->getPY() - 1);
			break;
		case KEY_DOWN:
		case 's':
		case 'k':
			if (this->getPY() < this->_bottom_g + 1)
				this->setPY(this->getPY() + 1);
			break;
		case KEY_RIGHT:
		case 'd':
		case 'l':
			if (this->getPX() < this->_right_g - 2)
				this->setPX(this->getPX() + 1);
			break;
		case KEY_LEFT:
		case 'a':
		case 'j':
			if (this->getPX() > this->_left_g + 1)
				this->setPX(this->getPX() - 1);
			break;
		case 0x20:
			_playerProjectiles->addObject(new SpaceObject(this->getPX(), this->getPY() - 1, UP, false));
			break;
	
		default:
			break;
	}
}

void Game::collisionChecks()
{
	for(int i = 0; i < _asteroids->getObjCount(); i++)
		if (_playerProjectiles->collisionCheck(_asteroids->getObj(i), _asteroids->getMaxX()))
		{
			_asteroids->destroyObject(i);
			_score++;
		}
	for(int i = 0; i < _enemyProjectiles->getObjCount(); i++)
		if (_playerProjectiles->collisionCheck(_enemyProjectiles->getObj(i), _enemyProjectiles->getMaxX()))
		{
			_enemyProjectiles->destroyObject(i);
			_score += 3;
		}
	for(int i = 0; i < _enemies->getObjCount(); i++)
		if (_playerProjectiles->collisionCheck(_enemies->getObj(i), _enemies->getMaxX()))
		{
			_enemies->destroyObject(i);
			_score += 2;
		}
	if (_enemyProjectiles->collisionCheck(_player) || _asteroids->collisionCheck(this->_player)
		|| _enemies->collisionCheck(this->_player))
		_gameOver = true;
}
