/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:18:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 23:59:28 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <string>

#include "Player.hpp"

int main()
{
	initscr();
	noecho();
	cbreak();

	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);

	WINDOW *playwin = newwin(20, 50, (y_max/2)-10, 10);
	box(playwin, 0, 0);
	refresh();
	wrefresh(playwin);
	
	Player *p = new Player(playwin, 1, 1, '@');

	do
	{
		p->display();
		wrefresh(playwin);
	} while (p->getMv() != 'x');
	

	endwin();
	return 0;
}

// https://github.com/fundamelon/terminal-game-tutorial
