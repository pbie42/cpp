/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:18:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 17:31:20 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <string>

int main()
{
	initscr();
	noecho();
	cbreak();

	int y, x, y_beg, x_beg, y_max, x_max;

	// gets xy position of cursor in the window you're working in.
	getyx(stdscr, y, x);
	// gets start xy position of the window you're working in.
	getbegyx(stdscr, y_beg, x_beg);
	// gets height and width of whatever window you specify
	getmaxyx(stdscr, y_max, x_max);

	mvprintw(y_max/2, x_max/2,"%d %d %d %d %d %d", y, x, y_beg, x_beg, y_max, x_max);

	getch();
	endwin();
	return 0;
}
