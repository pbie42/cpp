/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:18:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 17:47:21 by pbie             ###   ########.fr       */
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

	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);
	int height, width, startY, startX;
	height = 6;
	width = x_max - 12;
	startY = y_max - 8;
	startX = 5;
	WINDOW *menuwin = newwin(height, width, startY, startX);
	box(menuwin, 0, 0);
	refresh();
	wrefresh(menuwin);

	// makes it so we can use arrow keys
	keypad(menuwin, true);

	std::string choices[3] = {"walk", "jog", "run"};
	int choice;
	int highlight = 0;

	while(1){
		for(int i = 0; i < 3; i++)
		{
			if (i == highlight)
				wattron(menuwin, A_REVERSE);
			mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
			wattroff(menuwin, A_REVERSE);
		}
		choice = wgetch(menuwin);

		switch (choice)
		{
			case KEY_UP:
					highlight--;
					if (highlight < 0) highlight = 0;
				break;
			case KEY_DOWN:
					highlight++;
					if (highlight > 2) highlight = 2;
				break;
			default:
				break;
		}
		if (choice == 10)
			break;
	}
	
	printw("Your choice was %s", choices[highlight].c_str());


	getch();
	endwin();
	return 0;
}
