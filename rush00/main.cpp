/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <pbie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:18:39 by pbie              #+#    #+#             */
/*   Updated: 2019/03/31 15:44:40 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ncurses.h>

#include "Game.hpp"

int main()
{
	Game *game = new Game();

	int initStatus = game->init();

	if (initStatus == 0)
		game->run();
	
	game->close();
	delete game;
	return 0;
}
