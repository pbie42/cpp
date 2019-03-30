/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:10:54 by pbie              #+#    #+#             */
/*   Updated: 2019/03/30 16:26:45 by pbie             ###   ########.fr       */
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

	int x, y;
	x = y = 10;

	// move the cursor to the specified location
	move(y, x);

	// prints a string (const char *) to a window
	printw("Hello World!");

	// refreshes the screen to match whats in memory
	// refresh();

	// waits for user input, returns int value of that key
	int c = getch();
	// clears the screen
	clear();

	move(0, 0);
	printw("%d", c);


	getch();

	// Deallocates memory ends ncurses
	endwin();
	return 0;
}
