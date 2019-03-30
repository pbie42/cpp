/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:10:54 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 17:14:00 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <string>

int main()
{
	// Initialize screen
	// sets up memory
	initscr();
	// raw makes it so it takes in any input and ignores ctrl c exiting
	raw();
	// allows ctrl-c to exit program
	cbreak();

	// prevents user input from being displayed on the screen
	noecho();

	int height, width, start_y, start_x;
	height = 10;
	width = 30;
	start_x = start_y = 10;

	WINDOW *win = newwin(height, width, start_y, start_x);

	// refreshes entire window
	refresh();

	// adds a border to your window
	box(win, 0, 0);
	// like printw but only to a specific window
	// wprintw(win, "this is my box");
	if (!has_colors())
	{
		mvwprintw(win, 1, 2, "terminal has no colors");
	}
	else
		start_color();
	init_pair(1, COLOR_CYAN, COLOR_WHITE);

	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 1, 1, "this is my box");
	printw("Testing");
	wattroff(win, COLOR_PAIR(1));
	// refreshes only the window we created (win)
	wrefresh(win);
	
	// int c = getch();
	getch();
	getch();
	getch();
	
	endwin();
	return 0;
}
